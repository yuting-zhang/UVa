#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int main(){
    int c;
    scanf("%d", &c);
    while (c--){
        int n, m;
        scanf("%d %d", &n, &m);
        vector<vector<ii>> adjList(n);
        for (int i = 0; i < m; i++){
            int x, y, t;
            scanf("%d %d %d", &x, &y, &t);
            adjList[x].push_back({y, t});
        }

        vector<int> dist(n, (1 << 30));
        dist[0] = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n; j++)
                for (auto it: adjList[j]){
                    int u = j, v = it.first, w = it.second;
                    dist[v] = min(dist[v], dist[u] + w);
                }
        bool negativeCycle = false;
        for (int i = 0; !negativeCycle && i < n; i++)
            for (auto it: adjList[i]){
                int u = i, v = it.first, w = it.second;
                if (dist[u] + w < dist[v]){
                    negativeCycle = true;
                    break;
                }
            }
        if (negativeCycle)
            printf("possible\n");
        else
            printf("not possible\n");
    }
}
