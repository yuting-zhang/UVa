#include <iostream>
#include <vector>

using namespace std;

// run time was 2.982s and time limit is 3.000s.
// Probably should just use built-in arrays rather than vectors
int main(){
    int coins[5] = {1, 5, 10, 25, 50};
    int money;
    while (cin >> money)
    {
        vector<int> dp(money + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < 5; ++i)
            for (int j = 1; j <= money; ++j)
                if (j - coins[i] >= 0)
                    dp[j] += dp[j - coins[i]];
        cout << dp[money] << "\n";
    }
    return 0;
}
