#include <bits/stdc++.h>

using namespace std;

int main() {
    string status;
    while (cin >> status) {
        int n = status.size();
        vector<vector<long long>> path(n, vector<long long>(n));

        long long answer = 0;

        for (int row = 0; row < n; row++)
            path[row][0] = 1;

        for (int col = 0; col < n; col++) {
            if (status[col] != '?') {
                int placement = 0;
                if (status[col] >= '1' && status[col] <= '9')
                    placement = (status[col] - '0') - 1;
                else
                    placement = (status[col] - 'A') + 9;
                    
                for (int row = 0; row < n; row++)
                    if (row != placement)
                        path[row][col] = 0;
                    else if (col < n - 1) {
                        for (int k = 0; k < n; k++)
                            if (abs(k - row) > 1)
                                path[k][col + 1] = path[row][col];
                    }
            }
            else if (col < n - 1) {
                for (int row = 0; row < n; row++)
                    for (int k = 0; k < n; k++)
                        if (abs(k - row) > 1)
                            path[k][col + 1] += path[row][col];
            }
        }

        for (int row = 0; row < n; row++)
            answer += path[row][n - 1];
        cout << answer << "\n";
    }

    return 0;
}
