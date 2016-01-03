#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N, K;
    while (scanf("%d %d", &N, &K) && N && K){
        int memo[105][105];
        memset(memo, 0, sizeof memo);
        memo[0][0] = 1;
        for (int i = 0; i <= N; i++)
            for (int j = 1; j <= K; j++)
                for (int k = 0; k <= i; k++)
                    memo[i][j] = (memo[i][j] + memo[k][j - 1]) % 1000000;
        printf("%d\n", memo[N][K]);
    }
    return 0;
}
