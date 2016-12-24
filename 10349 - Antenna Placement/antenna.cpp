#include <bits/stdc++.h>

using namespace std;

int augment(int u, const vector<vector<int>> &adj_list, 
            vector<int> &match, vector<bool> &visited) {
    if (visited[u])
        return 0;
    visited[u] = true;
    for (int v : adj_list[u])
        if (match[v] == -1 || augment(match[v], adj_list, match, visited)) {
            match[v] = u;
            return 1;
        }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int h, w;
        scanf("%d %d", &h, &w);
        int grid[h][w];
        memset(grid, -1, sizeof grid);

        vector<vector<int>> adj_list;
        vector<bool> left;
        adj_list.reserve(h * w);
        left.reserve(h * w);

        for (int r = 0; r < h; r++)
            for (int c = 0; c < w; c++) {
                char ch;
                scanf(" %c", &ch);
                if (ch == '*') {
                    grid[r][c] = adj_list.size();
                    adj_list.push_back(vector<int>());
                    left.push_back((r + c) % 2);

                    if (r > 0 && grid[r - 1][c] >= 0) {
                        adj_list[grid[r][c]].push_back(grid[r - 1][c]);
                        adj_list[grid[r - 1][c]].push_back(grid[r][c]);
                    }
                    if (c > 0 && grid[r][c - 1] >= 0) {
                        adj_list[grid[r][c]].push_back(grid[r][c - 1]);
                        adj_list[grid[r][c - 1]].push_back(grid[r][c]);
                    }
                }
            }


        vector<int> match(adj_list.size(), -1);
        vector<bool> visited;

        int MCBM = 0;

        for (int i = 0; i < adj_list.size(); i++) {
            if (left[i]) {
                visited.assign(adj_list.size(), false);
                MCBM += augment(i, adj_list, match, visited);
            }
        }

        printf("%lu\n", adj_list.size() - MCBM);
    }
    return 0;
}
