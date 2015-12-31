#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long dp[30050];
const int coins[] = {1, 5, 10, 25, 50};

int main(){
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 0; i < 5; i++)
        for (int j = 1; j <= 30050; j++)
            if (j - coins[i] >= 0)
                dp[j] += dp[j - coins[i]];

    int n;
    while (scanf("%d", &n) == 1)
        if (dp[n] == 1)
            printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %lld ways to produce %d cents change.\n", dp[n], n);

    return 0;
}
