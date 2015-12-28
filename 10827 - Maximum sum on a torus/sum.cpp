#include <cstdio>
#include <climits>
#include <cstring>

using namespace std;

int matrix[200][200];
int sum[200][200];

int N;

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &matrix[i][j]);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N - 1; j++)
                matrix[i][j + N] = matrix[i][j];
        for (int i = 0; i < N - 1; i++)
            for (int j = 0; j < 2 * N - 1; j++)
               matrix[i + N][j] = matrix[i][j];

        for (int i = 0; i < 2 * N - 1; i++)
            for (int j = 0; j < 2 * N - 1; j++){
                sum[i][j] = matrix[i][j];
                if (j > 0)
                    sum[i][j] += sum[i][j - 1];
            }

        int answer = INT_MIN;
        for (int i = 0; i < 2 * N - 1; i++)
            for (int j = i; j < i + N && j < 2 * N - 1; j++){
                int local_best = 0, begin = 0;
                for (int k = 0; k < 2 * N - 1; k++){
                    if (local_best < 0){
                        local_best = 0;
                        begin = k;
                    }

                    local_best += sum[k][j];
                    if (i > 0)
                        local_best -= sum[k][i - 1];
                    if (k - begin + 1 > N){
                        local_best -= sum[begin][j];
                        if (i > 0)
                            local_best += sum[begin][i - 1]; 
                        begin++;
                        int value = 0;
                        for (int l = begin; l < k; l++){
                            value += sum[l][j];
                            if (i > 0)
                                value -= sum[l][i - 1];
                            if (value < 0){
                                begin = l + 1;
                                local_best -= value;
                                value = 0;
                            }
                        }
                    } 
                    if (local_best > answer)
                        answer = local_best;
                }
            }
        printf("%d\n", answer);
    }
}
