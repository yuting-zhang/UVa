#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int m, n;

int price[105], value[105];

int memo[11000][105];

int dp(int money, int item){
    if (money == 0)
        return 0;
    if (item < 0 || money < 0)
        return -2;

    if (memo[money][item] != -1)
        return memo[money][item];

    int& cell = memo[money][item];
    cell = -2;
    if (money >= price[item]){
        int buy = dp(money - price[item], item - 1);
        if (buy != -2)
            cell = value[item] + buy;
    }
    int skip = dp(money, item - 1);
    if (skip > cell)
        cell = skip;
    return cell;
}

int main(){
    while (scanf("%d %d", &m, &n) == 2){
        for (int i = 0; i < n; i++)
            scanf("%d %d", &price[i], &value[i]);
        int new_m = m;
        if (m > 1800)
            new_m = m + 200;

        int answer = 0;
        memset(memo, -1, sizeof memo);

        for (int i = 0; i <= new_m; i++){
            if (m <= 2000 && i > m && i <= 2000)
                continue;
            int result = dp(i, n - 1);
            if (result > answer)
                answer = result;
        }

        printf("%d\n", answer);
        
    }
}
