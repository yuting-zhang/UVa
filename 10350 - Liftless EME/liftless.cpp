#include <bits/stdc++.h>

using namespace std;

void toposort(int u, const vector<vector<pair<int, int>>> &adj_list,
    vector<bool> &visited, vector<int> &topo_order) {
    visited[u] = true;
    for (auto v : adj_list[u]) {
        if (!visited[v.first])
            toposort(v.first, adj_list, visited, topo_order);
    }
    topo_order.push_back(u);
}

int main() {
    string test_name;
    while (cin >> test_name) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj_list(n * m);
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < m; k++) {
                    int walk_time;
                    cin >> walk_time;
                    adj_list[i * m + j].push_back({(i + 1) * m + k, walk_time});
                }
                    
        vector<bool> visited(n * m, false);
        vector<int> topo_order;

        for (int i = 0; i < n * m; i++)
            if (!visited[i])
                toposort(i, adj_list, visited, topo_order);

        reverse(topo_order.begin(), topo_order.end());

        int answer = INT_MAX;
        vector<int> dist(n * m, INT_MAX);

        for (int i = 0; i < n * m; i++) {
            int u = topo_order[i];
            if (i < m)
                dist[u] = 0;

            if (i >= (n - 1) * m)
                answer = min(answer, dist[u]);

            for (auto v : adj_list[u]) 
                dist[v.first] = min(dist[v.first], dist[u] + v.second);
        }

        answer += 2 * (n - 1);
        cout << test_name << "\n" << answer << "\n";
    }
    return 0;
}
