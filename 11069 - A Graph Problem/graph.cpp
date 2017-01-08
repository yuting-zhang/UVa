#include <bits/stdc++.h>

using namespace std;

int main() {
    int dp[76] = {1,2,2};
    for (int i = 3; i < 76; i++)
        dp[i] = dp[i - 2] + dp[i - 3];

    int n;
    while (scanf("%d", &n) == 1)
        printf("%d\n", dp[n - 1]);
    return 0;
}
