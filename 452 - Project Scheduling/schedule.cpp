#include <bits/stdc++.h>

using namespace std;

void construct(int &N, vector<vector<int>> &adj_list, vector<int> &cost) {
    string line;
    int hash[26];
    memset(hash, -1, sizeof hash);
    while (getline(cin, line) && !line.empty()) {
        istringstream sin(line);
        char node;
        sin >> node;
        if (hash[node - 'A'] == -1) {
            hash[node - 'A'] = N++;
            adj_list.push_back(vector<int>());
            cost.push_back(0);
        }
        sin >> cost[hash[node - 'A']];

        string prev;
        sin >> prev;
        for (char p: prev) {
            if (hash[p - 'A'] == -1) {
                hash[p - 'A'] = N++;
                adj_list.push_back(vector<int>());
                cost.push_back(0);
            }
            adj_list[hash[p - 'A']].push_back(hash[node - 'A']);
        }
    }
}

void toposort(int u, const vector<vector<int>> &adj_list, vector<int> &topo_order,
    vector<bool> &visited) {

    visited[u] = true;
    for (int v : adj_list[u])
        if (!visited[v])
            toposort(v, adj_list, topo_order, visited);

    topo_order.push_back(u);
}

int main() {
    int T;
    string line;
    getline(cin, line);
    T = stoi(line);
    getline(cin, line);

    for (int test_case = 0; test_case < T; test_case++) {
        int N = 0;
        vector<vector<int>> adj_list;
        vector<int> cost;

        construct(N, adj_list, cost);

        vector<int> topo_order;
        vector<bool> visited(N, false);
        for (int i = 0; i < N; i++)
            if (!visited[N])
                toposort(i, adj_list, topo_order, visited);
        reverse(topo_order.begin(), topo_order.end());

        int answer = 0;
        vector<int> dist(N);

        for (int u : topo_order) {
            answer = max(answer, cost[u] + dist[u]);
            for (int v: adj_list[u])
                dist[v] = max(dist[v], cost[u] + dist[u]);
        }

        if (test_case != 0)
            cout << "\n";
        cout << answer << "\n";
    }
    return 0;
}
