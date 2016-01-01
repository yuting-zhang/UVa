#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

int coins[105];
int memo[20050];

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        int p, n;
        scanf("%d %d", &p, &n);
        int max_coin = 0;

        for (int i = 0; i < n; i++){
            scanf("%d", &coins[i]);
            if (coins[i] > max_coin)
                max_coin = coins[i];
        }

        memset(memo, -1, sizeof memo);
        memo[0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = p + max_coin; j > 0; j--)
                if (j - coins[i] >= 0 && memo[j - coins[i]] != -1)
                    if (memo[j] == -1 || memo[j - coins[i]] + 1 < memo[j])
                        memo[j] = memo[j - coins[i]] + 1;

        int answer = p;
        while (memo[answer] == -1)
            answer++;
        printf("%d %d\n", answer, memo[answer]);
    }
    return 0; 
}
