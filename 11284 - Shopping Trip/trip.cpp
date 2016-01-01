#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int adjMat[60][60];
int N, M;
int store[15];
int save[15];
int P;
int memo[15][1 << 14];

void floyed_warshall(){
    for (int k = 0; k <= N; k++)
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++)
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}

int dp(int pos, int mask){
    if (mask == (1 << (P + 1)) - 1)
        return -adjMat[store[pos - 1]][0];

    if (memo[pos][mask] != (1 << 29))
        return memo[pos][mask];

    int& cell = memo[pos][mask];
    cell = -adjMat[store[pos - 1]][0];

    for (int i = 1; i <= P; i++)
        if (!(mask & (1 << i))){
            int result = -adjMat[store[pos - 1]][store[i - 1]] + save[i - 1] + dp(i, mask | (1 << i));
            if (result > cell)
                cell = result;
        }
    
    return cell;
}


int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d %d", &N, &M);
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++)
                adjMat[i][j] = 1 << 29;
        for (int i = 0; i < M; i++){
            int source, dest;
            int w1, w2;
            scanf("%d %d %d.%d", &source, &dest, &w1, &w2);
            adjMat[source][dest] = adjMat[dest][source] = min(adjMat[source][dest], w1 * 100 + w2);
        }

        floyed_warshall();

        scanf("%d", &P);
        for (int i = 0; i < P; i++){
            int s1, s2;
            scanf("%d %d.%d", &store[i], &s1, &s2);
            save[i] = s1 * 100 + s2;
        }

        for (int i = 0; i <= P; i++)
            for (int j = 0; j <= (1 << (P + 1)); j++)
                memo[i][j] = (1 << 29);

        int answer = dp(0, 1);
        if (answer > 0)
            printf("Daniel can save $%.2f\n", answer / 100.0);
        else
            printf("Don't leave the house\n");
    }
    return 0;
}
