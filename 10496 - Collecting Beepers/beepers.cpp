#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>

using namespace std;

int T;
int adjMat[15][15];
int coords[15][2];
int num;

int memo[15][1 << 12];

int dp(int pos, int mask){
    if (mask == (1 << (num + 1)) - 1)
        return adjMat[pos][0];
    if (memo[pos][mask] != -1)
        return memo[pos][mask];

    int& cell = memo[pos][mask];
    cell = INT_MAX / 2;

    for (int i = 1; i <= num; i++)
        if (!(mask & (1 << i))){
            int result = adjMat[pos][i] + dp(i, mask | (1 << i));
            if (result < cell)
                cell = result;
        }
    return cell;
}

int main(){
    scanf("%d", &T);
    while (T--){
        int x_size, y_size;
        scanf("%d %d", &x_size, &y_size);
        scanf("%d %d", &coords[0][0], &coords[0][1]);
        scanf("%d", &num);
        for (int i = 0; i < num; i++)
            scanf("%d %d", &coords[i + 1][0], &coords[i + 1][1]);
        for (int i = 0; i <= num; i++)
            for (int j = i; j <= num; j++)
                adjMat[i][j] = adjMat[j][i] = abs(coords[i][0] - coords[j][0]) + abs(coords[i][1] - coords[j][1]);
        memset(memo, -1, sizeof memo);
        printf("The shortest path has length %d\n", dp(0, 1));

    }
    return 0;
}
