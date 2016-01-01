#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

int conValue[50], infoValue[50];
int memo[310][310];

int main(){
    int n;
    scanf("%d", &n);
    while (n--){
        int m, S;
        scanf("%d %d", &m, &S);
        for (int i = 0; i < m; i++)
            scanf("%d %d", &conValue[i], &infoValue[i]);
        int answer = INT_MAX;

        memset(memo, -1, sizeof memo);
        memo[0][0] = 0;

        for (int i = 0; i <= S; i++)
            for (int j = 0; j <= S; j++)
                for (int k = 0; k < m; k++){
                    if (i - conValue[k] >= 0 && j - infoValue[k] >= 0){
                        int& cell = memo[i - conValue[k]][j - infoValue[k]];
                        if (cell != -1 && (memo[i][j] == -1 || cell + 1 < memo[i][j]))
                            memo[i][j] = cell + 1;
                        if (memo[i][j] != -1 && i * i + j * j == S * S && memo[i][j] < answer)
                            answer = memo[i][j];
                    }
                }
        if (answer == INT_MAX)
            printf("not possible\n");
        else
            printf("%d\n", answer);
    }
    return 0;
}
