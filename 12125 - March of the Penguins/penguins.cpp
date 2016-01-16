#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct floe_t{
    int x, y, n, m;
};

vector<floe_t> floes;
int N, V, penguin;
double D;

vector<vector<int>> adjList, residue;

void buildGraph(){
    V = 2 * N + 1;
    adjList.assign(V, vector<int>());
    residue.assign(V, vector<int>(V, 0));

    for (int i = 0; i < N; i++){
        int in = 2 * i + 1, out = in + 1;
        adjList[0].push_back(in);
        adjList[in].push_back(0);
        residue[0][in] = floes[i].n;

        adjList[in].push_back(out);
        adjList[out].push_back(in);
        residue[in][out] = floes[i].m;
    }

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (pow(floes[i].x - floes[j].x, 2) + pow(floes[i].y - floes[j].y, 2) <= pow(D, 2)){
                int uIn = 2 * i + 1, uOut = uIn + 1,
                    vIn = 2 * j + 1, vOut = vIn + 1;
                adjList[uOut].push_back(vIn);
                adjList[vIn].push_back(uOut);
                adjList[vOut].push_back(uIn);
                adjList[uIn].push_back(vOut);
                residue[uOut][vIn] = residue[vOut][uIn] = (1 << 29);
            }
}

vector<int> parent;
int max_flow, flow, blocking_flow, s, t;

void augment(int v, int min_edge){
    if (v == s){
        flow = min_edge;
        return;
    }
    else if (parent[v] != -1){
        augment(parent[v], min(residue[parent[v]][v], min_edge));
        residue[parent[v]][v] -= flow;
        residue[v][parent[v]] += flow;
    }
}

void Dinic(){   
    max_flow = 0;
    while (true){
        parent.assign(V, -1);
        queue<int> q;
        vector<bool> visited(V, false);
        q.push(s);
        visited[s] = true;
        while (!q.empty()){
            int u = q.front();
            q.pop();
            if (u == t)
                break;
            for (int v : adjList[u])
                if (!visited[v] && residue[u][v] > 0){
                    parent[v] = u;
                    visited[v] = true;
                    q.push(v);
                }
        }
        blocking_flow = 0;
        for (int u : adjList[t])
            if (residue[u][t] > 0){
                flow = 0;
                augment(u, residue[u][t]);
                residue[u][t] -= flow;
                residue[t][u] += flow;
                blocking_flow += flow;
            }
        if (blocking_flow == 0)
            break;
        max_flow += blocking_flow;
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d %lf", &N, &D);
        floes.assign(N, floe_t());
        penguin = 0;

        for (int i = 0; i < N; i++){
            scanf("%d %d %d %d", &floes[i].x, &floes[i].y, &floes[i].n, &floes[i].m);
            penguin += floes[i].n;
        }

        buildGraph();
        vector<int> answer;
        auto backup = residue;
        s = 0;
        for (int i = 0; i < N; i++){
            t = i * 2 + 1;
            Dinic();
            residue = backup;
            if (max_flow == penguin)
                answer.push_back(i);
        }
        if (answer.empty())
            printf("-1\n");
        else{
            printf("%d", answer[0]);
            for (int i = 1; i < answer.size(); i++)
                printf(" %d", answer[i]);
            printf("\n");
        }
    }
    return 0;
}
