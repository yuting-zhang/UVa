#include <iostream>
#include <vector>

using namespace std;

int main(){
    int coins[5] = {1, 5, 10, 25, 50};
    int money;
    int dp[7500] = {0};
    dp[0] = 1;
    for (int i = 0; i < 5; ++i)
        for (int j = 1; j <= 7489; ++j)
            if (j - coins[i] >= 0)
                dp[j] += dp[j - coins[i]];

    while (scanf("%d", &money) == 1) {
        printf("%d\n", dp[money]);
    }
    return 0;
}
