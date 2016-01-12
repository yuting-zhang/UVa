#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> ii;

int main(){
    int T;
    scanf("%d", &T);
    bool first_case = true;
    while (T--){
        if (first_case)
            first_case = false;
        else
            printf("\n");
        int N, E, T, M;
        scanf("%d %d %d %d", &N, &E, &T, &M);
        vector<vector<ii>> adjList(N);
        E--;
        for (int i = 0; i < M; i++){
            int a, b, t;
            scanf("%d %d %d", &a, &b, &t);
            a--, b--;
            adjList[b].push_back({a, t});
        }

        vector<int> dist(N, (1 << 30));
        dist[E] = 0;
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({dist[E], E});
        while (!pq.empty()){
            ii front = pq.top();
            pq.pop();
            int cost = front.first, u = front.second;
            if (cost > dist[u])
                continue;

            for (const auto& it: adjList[u]){
                int w = it.second, v = it.first;
                if (w + cost < dist[v]){
                    dist[v] = w + cost;
                    pq.push({dist[v], v});
                }
            }
        }
        int answer = 0;
        for (int i = 0; i < N; i++)
            if (dist[i] <= T)
                answer++;
        printf("%d\n", answer);
    }
    return 0;
}
