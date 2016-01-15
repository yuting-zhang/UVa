#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct edge_t{
    int u, v, residue;
    edge_t* backward;
};

int n, s, t, c;
vector<vector<edge_t*>> adjList;
vector<edge_t> edgeList;

int max_flow, flow;
vector<edge_t*> parent;

void augment(edge_t* edge, int min_edge){
    if (edge){
        int new_min_edge = min(min_edge, edge->residue);
        if (edge->u == s)
            flow = new_min_edge;
        else
            augment(parent[edge->u], new_min_edge);

        edge->residue -= flow;
        edge->backward->residue += flow;
    }
}

int main(){
    int network = 0;
    while (scanf("%d", &n) && n){
        network++;
        scanf("%d %d %d", &s, &t, &c);
        s--, t--;
        adjList.assign(n, vector<edge_t*>());
        edgeList.assign(c * 2, edge_t());
        for (int i = 0; i < c; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;

            edgeList[i * 2] = {u, v, w, nullptr};
            edgeList[i * 2 + 1] = {v, u, w, nullptr};
            edgeList[i * 2].backward = &edgeList[i * 2 + 1];
            edgeList[i * 2 + 1].backward = &edgeList[i * 2];

            adjList[u].push_back(&edgeList[i * 2]);
            adjList[v].push_back(&edgeList[i * 2 + 1]);
        }

        max_flow = 0;
        while (true){
            parent.assign(n, nullptr);
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(s);
            visited[s] = true;

            while (!q.empty()){
                int u = q.front();
                q.pop();
                if (u == t)
                    break;
                for (edge_t* edge : adjList[u])
                    if (!visited[edge->v] && edge->residue > 0){
                        parent[edge->v] = edge;
                        q.push(edge->v);
                        visited[edge->v] = true;
                    }
            }

            flow = 0;
            augment(parent[t], (1 << 29));
            if (flow == 0)
                break;
            max_flow += flow;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n", network, max_flow);

    }
}
