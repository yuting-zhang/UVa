#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> ii;

int M, W, V, s, t;

vector<int> machine;
vector<pair<ii, int>> wire;

vector<vector<int>> adjList, residue;
int max_flow, flow, blocking_flow;

void buildGraph(){
    s = 0, t = V - 1;
    adjList.assign(V, vector<int>());
    residue.assign(V, vector<int>(V, 0));
    for (int i = 0; i < M - 2; i++){
        int in = 1 + i * 2, out = in + 1;
        adjList[in].push_back(out);
        adjList[out].push_back(in);
        residue[in][out] = machine[i];
    }

    for (int i = 0; i < W; i++){
        int uIn, uOut, vIn, vOut;
        uIn = (wire[i].first.first - 1) * 2 + 1;
        uOut = uIn + 1;
        vIn = (wire[i].first.second - 1)* 2 + 1;
        vOut = vIn + 1;
        if (wire[i].first.first == 0)
            uIn = uOut = 0;
        if (wire[i].first.second == 0)
            vIn = vOut = 0;
        if (wire[i].first.first == M - 1)
            uIn = uOut = t;
        if (wire[i].first.second == M - 1)
            vIn = vOut = t;

        adjList[uOut].push_back(vIn);
        adjList[vIn].push_back(uOut);
        if (!(uIn == uOut && vIn == vOut)){
            adjList[vOut].push_back(uIn);
            adjList[uIn].push_back(vOut);
        }
        residue[uOut][vIn] = residue[vOut][uIn] = wire[i].second;
    }
}

vector<int> parent;

void augment(int v, int min_edge){
    if (v == s){
        flow = min_edge;
        return; 
    }
    else if (parent[v] != -1){
        augment(parent[v], min(min_edge, residue[parent[v]][v]));
        residue[parent[v]][v] -= flow;
        residue[v][parent[v]] += flow;
    }
}

void Dinic(){
    max_flow = 0;
    while (true){
        vector<bool> visited(V, false);
        parent.assign(V, -1);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while (!q.empty()){
            int u = q.front();
            q.pop();
            if (u == t)
                break;
            for (int v : adjList[u])
                if (!visited[v] && residue[u][v] > 0){
                    visited[v] = true;
                    q.push(v);
                    parent[v] = u;
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
    while (scanf("%d %d", &M, &W) && M){
        machine.assign(M - 2, 0);
        wire.assign(W, pair<ii, int>());

        for (int i = 0; i < M - 2; i++){
            int id;
            scanf("%d", &id);
            scanf("%d", &machine[id - 2]);
        }

        for (int i = 0; i < W; i++){
            scanf("%d %d %d", &wire[i].first.first, &wire[i].first.second, &wire[i].second);
            wire[i].first.first--, wire[i].first.second--;
        }
        
        V = (M - 2) * 2 + 2;
        buildGraph();
        Dinic();
        printf("%d\n", max_flow);
    }
}
