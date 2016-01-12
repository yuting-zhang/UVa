#include <iostream>
#include <utility>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int main(){
    int n;
    int set_count = 0;
    while (scanf("%d", &n) == 1){
        set_count++;
        printf("Set #%d\n", set_count);
        vi busyness(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &busyness[i]);
        vector<vector<ii>> adjList(n);
        int r;
        scanf("%d", &r);
        for (int i = 0; i < r; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            u--, v--;
            adjList[u].push_back({v, pow(busyness[v] - busyness[u], 3)});
        }

        vi dist(n, (1 << 29));
        dist[0] = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n; j++)
                for (auto it: adjList[j]){
                    int u = j, v = it.first, w = it.second;
                    if (dist[u] != (1 << 29) && dist[u] + w < dist[v])
                        dist[v] = dist[u] + w;
                }

        vector<bool> inNegCycle(n, false);
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n; j++)
                for (auto it: adjList[j]){
                    int u = j, v = it.first, w = it.second;
                    if (dist[u] != (1 << 29) && dist[u] + w < dist[v]){
                        dist[v] = dist[u] + w;
                        inNegCycle[v] = true;
                    }
                }

        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; i++){
            int d;
            scanf("%d", &d);
            d--;
            if (d >=0 && d < n && !inNegCycle[i] && dist[d] >= 3 && dist[d] != (1 << 29))
                printf("%d\n", dist[d]);
            else
                printf("?\n");
        }

    }
}
