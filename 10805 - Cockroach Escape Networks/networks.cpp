#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

int main() {
    int N;
    cin >> N;
    for (int test_case = 0; test_case < N; test_case++) {
        int n, m, size;
        cin >> n >> m;
        vector<vector<int>> adj_mat(n + m, vector<int>(n + m, INF));
        size = n;

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj_mat[u][size] = 1;
            adj_mat[size][u] = 1;
            adj_mat[size][v] = 1;
            adj_mat[v][size] = 1;
            size++;
        }

        for (int i = 0; i < size; i++)
            adj_mat[i][i] = 0;

        for (int k = 0; k < size; k++)
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] +
                            adj_mat[k][j]);

        int solution = INF;

        for (int i = 0; i < size; i++) {
            int first = 0, second = 0;
            for (int j = 0; j < n; j++)
                if (adj_mat[i][j] >= first) {
                    second = first;
                    first = adj_mat[i][j];
                }
                else if (adj_mat[i][j] > second)
                    second = adj_mat[i][j];
           solution = min(solution, first + second); 
        }
        cout << "Case #" << test_case + 1 << ":\n";
        cout << solution / 2 <<"\n\n";

    }
    return 0;
}
