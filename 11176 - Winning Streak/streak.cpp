#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    double p;
    while (scanf("%d %lf", &n, &p) && n) {
        double dp[n + 1][n + 1];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j <= n; j++) {
                if (abs(dp[i][j]) < 1e-10)
                    continue;
                dp[i + 1][j] += dp[i][j] * (1 - p);
                for (int k = 1; k < n - i; k++) {
                    if (k <= j)
                        dp[i + k + 1][j] += dp[i][j] * pow(p, k) * (1 - p);
                    else
                        dp[i + k + 1][k] += dp[i][j] * pow(p, k) * (1 - p);
                }
                if (n - i <= j)
                    dp[n][j] += dp[i][j] * pow(p, n - i);
                else
                    dp[n][n - i] += dp[i][j] * pow(p, n - i);
            }

        double answer = 0;
        for (int i = 0; i <= n; i++)
            answer += i * dp[n][i];
            
        printf("%f\n", answer);
    }
    return 0;
}
