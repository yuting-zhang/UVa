#include <bits/stdc++.h>

using namespace std;

void toposort(int u, const vector<vector<int>> &adj_list, vector<bool> &visited, 
    vector<int> &topo_order) {
    visited[u] = true;
    for (int v : adj_list[u])
        if (!visited[v])
            toposort(v, adj_list, visited, topo_order);
    topo_order.push_back(u);
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        string name;
        int R, C;
        cin >> name >> R >> C;

        vector<vector<int>> grid(R, vector<int>(C));
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                cin >> grid[i][j];
        
        vector<vector<int>> adj_list(R * C);
        for (int i = 0; i < R; i++)
            for (int j = 0; j  < C; j++) {
                int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for (int k = 0; k < 4; k++) {
                    int r = i + dir[k][0], c = j + dir[k][1];
                    if (r >= 0 && r < R && c >= 0 && c < C) {
                        if (grid[i][j] > grid[r][c])
                            adj_list[i * C + j].push_back(r * C + c);
                    }
                }
            }

        vector<bool> visited(R * C, false);
        vector<int> topo_order;

        for (int i = 0; i < R * C; i++)
            if (!visited[i])
                toposort(i, adj_list, visited, topo_order);
        reverse(topo_order.begin(), topo_order.end());

        int answer = 0;
        vector<int> dist(R * C, 0);
        for (int u : topo_order) {
            answer = max(answer, dist[u] + 1);
            for (int v : adj_list[u])
                dist[v] = max(dist[v], dist[u] + 1);
        }
        cout << name << ": " << answer << "\n";
    }
}
