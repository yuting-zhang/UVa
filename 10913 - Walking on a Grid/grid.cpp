#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<vector<vector<long long>>>> vvvvll;
typedef vector<vector<vector<long long>>> vvvll;
typedef vector<vector<long long>> vvll;
typedef vector<long long> vll;

long long solve(int row, int col, int remain, int dir, 
                const vvll &grid, vvvvll &memo) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid.size())
        return LLONG_MIN / 2;

    if (grid[row][col] < 0)
        remain--;

    if (remain < 0)
        return LLONG_MIN / 2;


    if (row == 0 && col == 0) 
        return grid[0][0];

    long long &local = memo[row][col][remain][dir];
    if (local != LLONG_MIN)
        return local;
    else
        local = grid[row][col];

    long long result = LLONG_MIN;

    switch (dir) {
    case 0:
        result = max(solve(row, col - 1, remain, 0, grid, memo),
                    solve(row, col - 1, remain, 2, grid, memo));
        break;
    case 1:
        result = max(solve(row, col + 1, remain, 1, grid, memo),
                    solve(row, col + 1, remain, 2, grid, memo));
        break;
    case 2:
        result = max(max(solve(row - 1, col, remain, 0, grid, memo),
                        solve(row - 1, col, remain, 1, grid, memo)),
                        solve(row - 1, col, remain, 2, grid, memo));
        break;
    }

    if (result == LLONG_MIN / 2)
        local = LLONG_MIN / 2;
    else
        local += result;

    return local;
}

int main() {
    int N, k, test_case = 0;
    while (cin >> N >> k && N) {
        vvll grid(N, vll(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> grid[i][j];

        // 1st dimension: row
        // 2nd dimension: column
        // 3rd dimension: negative remaining
        // 4th dimension: from which direction. 0 left, 1 right, 2 up.
        vvvvll memo(N, vvvll(N, vvll(k + 1, vll(3, LLONG_MIN))));

        long long answer = max(solve(N - 1, N - 1, k, 0, grid, memo),
                               solve(N - 1, N - 1, k, 2, grid, memo));

        cout << "Case " << ++test_case << ": ";
        if (answer == LLONG_MIN / 2)
            cout << "impossible\n";
        else
            cout << answer << "\n";
    }
    return 0;
}
