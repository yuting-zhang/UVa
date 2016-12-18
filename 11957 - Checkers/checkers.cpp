#include <bits/stdc++.h>
#define MODULO 1000007

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test_case = 0; test_case < T; test_case++) {
        int N;
        cin >> N;
        vector<vector<char>> board(N, vector<char>(N));
        vector<vector<int>> path(N, vector<int>(N));

        for (int row = 0; row < N; row++)
            for (int col = 0; col < N; col++) {
                cin >> board[row][col];
                if (board[row][col] == 'W')
                    path[row][col] = 1;
            }

        for (int row = N - 1; row > 0; row--)
            for (int col = 0; col < N; col++) {
                if (col > 0 && board[row - 1][col - 1] == '.')
                    path[row - 1][col - 1] = (path[row - 1][col - 1] + path[row][col]) % MODULO;
                else if (row > 1 && col > 1 && board[row - 1][col - 1] == 'B' &&
                    board[row - 2][col - 2] == '.')
                    path[row - 2][col - 2] = (path[row - 2][col - 2] + path[row][col]) % MODULO;

                if (col < N - 1 && board[row - 1][col + 1] == '.')
                    path[row - 1][col + 1] = (path[row - 1][col + 1] + path[row][col]) % MODULO;
                else if (row > 1 && col < N - 2 && board[row - 1][col + 1] == 'B' &&
                    board[row - 2][col + 2] == '.')
                    path[row - 2][col + 2] = (path[row - 2][col + 2] + path[row][col]) % MODULO;
            }
        
        int answer = 0;
        for (int i = 0; i < N; i++)
            answer = (answer + path[0][i]) % MODULO;
        
        cout << "Case " << test_case + 1 << ": " << answer << "\n";
    }
    return 0;
}
