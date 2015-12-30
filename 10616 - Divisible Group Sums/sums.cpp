#include <iostream>
#include <cstdio>
#include <cstring>

int N, Q, D, M;
int numbers[205];
long long memo[205][25][15];

long long dp(int num, int sum, int left){
    if (left == 0)
        return sum == 0 ? 1 : 0;
    if (num == -1)
        return 0;
    if (memo[num][sum][left] != -1)
        return memo[num][sum][left];
   
    long long& cell = memo[num][sum][left];
    cell = 0;
    cell += dp(num - 1, sum, left);
    int new_sum = (sum + D - numbers[num] % D) % D;
    cell += dp(num - 1, new_sum, left - 1);
    return cell;
}

int main(){
    int set_count = 0;
    while (scanf("%d %d", &N, &Q) && N && Q){
        set_count++;
        printf("SET %d:\n", set_count);
        for (int i = 0; i < N; i++)
            scanf("%d", &numbers[i]);
        for (int i = 0; i < Q; i++){
            scanf("%d %d", &D, &M);
            memset(memo, -1, sizeof memo);
            printf("QUERY %d: %lld\n", i + 1, dp(N - 1, 0, M));
            
        }
    }
}
