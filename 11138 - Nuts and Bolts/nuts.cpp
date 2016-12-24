#include <bits/stdc++.h>

using namespace std;

int augment(int u, const vector<vector<int>> &adj_list,
            vector<int> &match, vector<bool> &visited) {
    if (visited[u])
        return 0;
    visited[u] = true;
    for (int v : adj_list[u]) {
        if (match[v] == -1 || augment(match[v], adj_list, match, visited)) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cases = 0; cases < T; cases++) {
        int bolts, nuts;
        scanf("%d %d", &bolts, &nuts);
        vector<vector<int>> adj_list(bolts);
        for (int i = 0; i < bolts; i++)
            for (int j = 0; j < nuts; j++) {
                int val;
                scanf("%d", &val);
                if (val)
                    adj_list[i].push_back(bolts + j);
            }

        int MCBM = 0;
        vector<int> match(bolts + nuts, -1);
        vector<bool> visited;

        for (int i = 0; i < bolts; i++) {
            visited.assign(bolts, false);
            MCBM += augment(i, adj_list, match, visited);
        }
        printf("Case %d: ", cases + 1);
        printf("a maximum of %d nuts and bolts ", MCBM);
        printf("can be fitted together\n");
    }
}
