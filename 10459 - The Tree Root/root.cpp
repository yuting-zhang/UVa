#include <bits/stdc++.h>

using namespace std;

void DFS(int node, const vector<vector<int>> &adj_list,
         vector<bool> &visited, 
         int len, int &long_dist, int start, vector<int> &path,
         set<int> &best, set<int> &worst) {
    path.push_back(node);
    visited[node] = true;

    if (len > long_dist) {
        best.clear();
        worst.clear();

        long_dist = len;
    }

    if (len == long_dist) {
        worst.insert(node);
        worst.insert(start);

        if (len % 2 == 0)
            best.insert(path[len / 2]);
        else {
            best.insert(path[len / 2]);
            best.insert(path[len / 2 + 1]);
        }
    }

    for (int dest : adj_list[node])
        if (!visited[dest]) {
            DFS(dest, adj_list, visited, len + 1, long_dist,
                start, path, best, worst);
        }

    visited[node] = false;
    path.pop_back();
}

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        vector<vector<int>> adj_list(N);
        for (int i = 0; i < N; i++) {
            int K;
            scanf("%d", &K);
            for (int j = 0; j < K; j++) {
                int node;
                scanf("%d", &node);
                adj_list[i].push_back(node - 1);
            }
        }

        vector<bool> visited(N, false);

        queue<pair<int, int>> q;
        visited[0] = true;
        q.push({0, 0});
        int long_dist = 0;
        
        int potential = 0;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int u = front.first;
            int len = front.second;
            if (len > long_dist) {
                long_dist = len;
                potential = u;
            }

            for (int v : adj_list[u])
                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, len + 1});
                }
        }


        visited.assign(N, false);
        vector<int> path;
        
        set<int> best, worst;

        DFS(potential, adj_list, visited, 0,
            long_dist, potential, path, best, worst);

        for (int node : worst)
            if (node != potential) {
                potential = node;
                break;
            }

        visited.assign(N, false);
        path.clear();
        DFS(potential, adj_list, visited, 0,
            long_dist, potential, path, best, worst);


        printf("Best Roots  :");
        for (int root : best)
            printf(" %d", root + 1);
        printf("\n");

        printf("Worst Roots :");
        for (int root : worst)
            printf(" %d", root + 1);
        printf("\n");
    }
    return 0;
}
