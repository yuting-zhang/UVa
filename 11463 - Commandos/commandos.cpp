#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    int adjMat[105][105];
    for (int test_case = 1; test_case <= T; test_case++){
        int N;
        scanf("%d", &N);
        for (int i = 0; i < 105; i++)
            for (int j = 0; j < 105; j++)
                adjMat[i][j] = (i == j ? 0 : (1 << 29));
        int R;
        scanf("%d", &R);
        for (int i = 0; i < R; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            adjMat[u][v] = adjMat[v][u] = 1;
        }

        int s, d;
        scanf("%d %d", &s, &d);

        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);

        int answer = 0;
        for (int i = 0; i < N; i++)
            answer = max(answer, adjMat[s][i] + adjMat[i][d]);
        
        printf("Case %d: %d\n", test_case, answer);
    }
    return 0;
}
