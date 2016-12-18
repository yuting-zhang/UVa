#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    bool first = true;

    while (cin >> m) {
        if (first)
            first = false;
        else
            cout << "\n";

        vector<vector<int>> adj_list(m);
        for (int i = 0; i < m; i++) {
            int n;
            cin >> n;
            for (int j = 0; j < n; j++) {
                int next;
                cin >> next;
                adj_list[i].push_back(next);
            }
        }

        vector<int> path(m, 0);
        path[0] = 1;
        int answer = 0;

        for (int u = 0; u < m; u++) {
            if (adj_list[u].empty())
                answer += path[u];
            for (int v : adj_list[u])
                path[v] += path[u];
        }
        cout << answer << "\n";
    }

    return 0;
}
