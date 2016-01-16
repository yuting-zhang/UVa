#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF (1 << 29)

int X, Y, P, V, s, t;

vector<vector<char>> graph;
vector<vector<int>> indexing;
vector<vector<int>> adjList, residue;

void buildGraph(){
    adjList.assign(V, vector<int>());
    residue.assign(V, vector<int>(V, 0));
    s = 0, t = V - 1;

    for (int i = 0; i < X; i++)
        for (int j = 0; j < Y; j++){
            if (graph[i][j] == '~')
                continue;
            int inNode = indexing[i][j] * 2 + 1, outNode = inNode + 1;
            adjList[inNode].push_back(outNode);
            adjList[outNode].push_back(inNode);

            switch (graph[i][j]){
            case '*':
                adjList[s].push_back(inNode);
                adjList[inNode].push_back(s);
                residue[s][inNode] = INF;
                residue[inNode][outNode] = 1;
                break;
            case '.':
                residue[inNode][outNode] = 1;
                break;
            case '@':
                residue[inNode][outNode] = INF;
                break;
            case '#':
                adjList[outNode].push_back(t);
                adjList[t].push_back(outNode);
                residue[outNode][t] = P;
                residue[inNode][outNode] = INF;
                break;
            }
        }  
    for (int i = 0; i < X; i++)
        for (int j = 0; j < Y; j++)
            if (graph[i][j] != '~'){
                int uIn = indexing[i][j] * 2 + 1, uOut = uIn + 1;
                if (i < X - 1 && graph[i + 1][j] != '~'){
                    int vIn = indexing[i + 1][j] * 2 + 1, vOut = vIn + 1;
                    adjList[uOut].push_back(vIn);
                    adjList[vIn].push_back(uOut);
                    adjList[vOut].push_back(uIn);
                    adjList[uIn].push_back(vOut);
                    residue[uOut][vIn] = residue[vOut][uIn] = INF;
                }
                if (j < Y - 1 && graph[i][j + 1] != '~'){
                    int vIn = indexing[i][j + 1] * 2 + 1, vOut = vIn + 1;
                    adjList[uOut].push_back(vIn);
                    adjList[vIn].push_back(uOut);
                    adjList[vOut].push_back(uIn);
                    adjList[uIn].push_back(vOut);
                    residue[uOut][vIn] = residue[vOut][uIn] = INF;
                }
            }
}

int max_flow, flow, blocking_flow;
vector<int> parent;

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
        vector<bool> visited(V, false);
        queue<int> q;
        parent.assign(V, -1);
        q.push(s);
        visited[s] = true;
        while (!q.empty()){
            int u = q.front();
            q.pop();
            if (u == t)
                break;
            for (int v: adjList[u])
                if (!visited[v] && residue[u][v] > 0){
                    parent[v] = u;
                    q.push(v);
                    visited[v] = true;
                }
        }
        blocking_flow = 0;
        for (int u: adjList[t])
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
    while (scanf("%d %d %d", &X, &Y, &P) == 3){
        graph.assign(X, vector<char>(Y));
        indexing.assign(X, vector<int>(Y));
        V = 0;
        for (int i = 0; i < X; i++)
            for (int j = 0; j < Y; j++){
                scanf(" %c ", &graph[i][j]);
                if (graph[i][j] != '~')
                    indexing[i][j] = V++;
            }
        V = V * 2 + 2;

        buildGraph();
        Dinic();
        printf("%d\n", max_flow);
    }
    return 0;
}
