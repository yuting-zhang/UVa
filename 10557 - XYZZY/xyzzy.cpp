#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
int n;
vi energy;
vector<vi> adjList;
vector<bool> visited;

void DFS(int node){
    visited[node] = true;
    for (int dest: adjList[node]){
        if (!visited[dest])
            DFS(dest);
    }
}

bool connectivityCheck(int source){
    visited.assign(n, false);
    DFS(source);
    return visited[n - 1];
}

int main(){
    while (scanf("%d", &n) && n != -1){
        energy.assign(n, 0);
        adjList.assign(n, vi());

        for (int i = 0; i < n; i++){
            scanf("%d", &energy[i]);
            int num;
            scanf("%d", &num);
            for (int j = 0; j < num; j++){
                int v;
                scanf("%d", &v);
                v--;
                adjList[i].push_back(v);
            }
        }

        bool winnable = false;
        
        vi dist(n, -1);
        dist[0] = 100;
        for (int i = 0; i < n - 1; i++)
            for (int u = 0; u < n; u++)
                for (int v : adjList[u]){
                    if (dist[u] != -1 && dist[u] + energy[v] > 0)
                        if (dist[u] + energy[v] > dist[v])
                            dist[v] = dist[u] + energy[v];
                }
        vector<bool> positiveCycle(n, false);
        for (int i = 0; i < n - 1; i++)
            for (int u = 0; u < n; u++)
                for (int v : adjList[u]){
                    if (dist[u] != -1 && dist[u] + energy[v] > 0)
                        if (dist[u] + energy[v] > dist[v]){
                            positiveCycle[u] = true;
                            dist[v] = dist[u] + energy[v];
                        }
                }
        bool reachable = false;
        for (int i = 0; !reachable && i < n; i++)
            if (positiveCycle[i])
                if (connectivityCheck(i))
                    reachable = true;

        if (reachable || dist[n - 1] > -1)
            winnable = true;
        if (winnable)
            printf("winnable\n");
        else
            printf("hopeless\n");
    }
    return 0;
}
