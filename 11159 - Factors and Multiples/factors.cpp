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
    for (int cases = 1; cases <= T; cases++) {
        int n;
        scanf("%d", &n);
        vector<int> A(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);

        int m;
        scanf("%d", &m);
        vector<int> B(m);
        for (int i = 0; i < m; i++)
            scanf("%d", &B[i]);

        vector<vector<int>> adj_list(n);
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                if (!B[j] || (A[i] &&  B[j] % A[i] == 0))
                    adj_list[i].push_back(j + n);

        int MCBM = 0;
        vector<int> match(n + m, -1);
        vector<bool> visited;
        for (int i = 0; i < n; i++) {
            visited.assign(n, false);
            MCBM += augment(i, adj_list, match, visited);
        }
        printf("Case %d: %d\n", cases, MCBM); 
    }

    return 0;
}
