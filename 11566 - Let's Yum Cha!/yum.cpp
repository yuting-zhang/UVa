#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int N, x, T, K, M;

int memo[1200][205][30];
int value[205], price[205];

int dp(int money, int item, int count){
    if (money == 0)
        return 0;
    if (item == K || count == N * 2)
        return -2;

    int& cell = memo[money][item][count];
    if (cell != -1)
        return cell;

    cell = -2;
    int pick = -2;
    if (price[item] <= money){
        pick = dp(money - price[item], item + 1, count + 1);
        if (pick != -2)
            pick += value[item];
    }

    cell = pick;
    int skip = dp(money, item + 1, count);
    if (skip > cell)
        cell = skip;
    return cell;
}

int main(){
    while (scanf("%d %d %d %d", &N, &x, &T, &K) && N){
        N++;
        x *= N;
        M = x;
        while ((int)(ceil((M + T * N) * 0.1)) + (M + T * N) > x)
            M--;
        for (int i = 0; i < K; i++){
            scanf("%d", &price[i * 2]);
            price[i * 2 + 1] = price[i * 2];
            value[i * 2] = 0;
            for (int j = 0; j < N; j++){
                int favor;
                scanf("%d", &favor);
                value[i * 2] += favor;
            }
            value[i * 2 + 1] = value[i * 2];
        }
        K *= 2;

        int answer = 0;
        memset(memo, -1, sizeof memo);
        for (int i = 0; i <= M; i++){
            int result = dp(i, 0, 0);
            if (result > answer)
                answer = result;
        }
        printf("%.2f\n", 1.0 * answer / N);
    }
}
