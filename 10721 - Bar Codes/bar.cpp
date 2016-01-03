#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n, k, m;
    while (scanf("%d %d %d", &n, &k, &m) == 3){
        long long memo[55][55];
        memset(memo, 0, sizeof memo);
        memo[0][0] = 1;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= k; j++)
                for (int k = i - 1; k >= 0 && k >= i - m; k--)
                    memo[i][j] += memo[k][j - 1];
        printf("%lld\n", memo[n][k]);
    }
    return 0;
}
