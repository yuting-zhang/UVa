#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

int wind[1050][10];
int memo[1050][10];

int main(){
    int N;
    scanf("%d", &N);
    while (N--){
        int X;
        scanf("%d", &X);
        X /= 100;
        for (int i = 9; i >= 0; i--)
            for (int j = 1; j <= X; j++)
                scanf("%d", &wind[j][i]);

        memset(memo, 8, sizeof memo);
        memo[0][0] = 0;

        for (int i = 1; i <= X; i++)
            for (int j = 0; j <= 9; j++){
                memo[i][j] = memo[i - 1][j] + 30 - wind[i][j];
                if (j > 0){
                    int climb = memo[i - 1][j - 1] + 60 - wind[i][j - 1];
                    if (climb < memo[i][j])
                        memo[i][j] = climb;
                }
                if (j < 9){
                    int sink = memo[i - 1][j + 1] + 20 - wind[i][j + 1];
                    if (sink < memo[i][j])
                        memo[i][j] = sink;
                }
                
            }
                
        printf("%d\n\n", memo[X][0]);
    }
    return 0;
}
