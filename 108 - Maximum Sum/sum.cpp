#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

int matrix[105][105];
int sum[105][105];
int N;

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &matrix[i][j]);


    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++){
            sum[i][j] = matrix[i][j];
            if (j > 0)
                sum[i][j] += sum[i][j - 1];
        }

    int answer = INT_MIN;

    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++){
            int best = 0;
            for (int k = 0; k < N; k++){
                if (best < 0)
                    best = 0;
                best += sum[k][j];
                if (i > 0)
                    best -= sum[k][i - 1];
                if (best > answer)
                    answer = best;
            }
        }
    printf("%d\n", answer);
}
