#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

typedef pair<int, int> ii;

vector<int> Dijkstra(int source, vector<vector<ii>>& adjList){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, source});
    vector<int> dist(adjList.size(), (1 << 29));
    dist[source] = 0;

    while (!pq.empty()){
        auto front = pq.top();
        pq.pop();
        int u = front.second, cost = front.first;
        if (cost > dist[u])
            continue;
        for (auto it: adjList[u]){
            int v = it.first, w = it.second;
            if (cost + w < dist[v]){
                dist[v] = cost + w;
                pq.push({cost + w, v});
            }
        }
    }
    return dist;
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        int N, M, s, t, p;
        scanf("%d %d %d %d %d", &N, &M, &s, &t, &p);
        vector<vector<ii>> adjList(N), reverseAdjList(N);
        s--, t--;

        for (int i = 0; i < M; i++){
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            u--, v--;
            adjList[u].push_back({v, c});
            reverseAdjList[v].push_back({u, c});
        }

        vector<int> dist = Dijkstra(s, adjList);
        vector<int> reverseDist = Dijkstra(t, reverseAdjList);
        
        int answer = -1;
        for (int i = 0; i < N; i++)
            for (auto it : adjList[i]){
                int u = i, v = it.first, w = it.second;
                if (dist[u] + reverseDist[v] + w <= p)
                    if (w > answer)
                        answer = w;
            }
        printf("%d\n", answer);
    }
}
