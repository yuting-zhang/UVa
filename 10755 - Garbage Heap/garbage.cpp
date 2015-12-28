#include <iostream>
#include <cstdio>

using namespace std;

long long heap[25][25][25];
long long sum[25][25][25];

int A, B, C;

void preprocessing(){
    for (int i = 0; i < A; i++)
        for (int j = 0; j < B; j++)
            for (int k = 0; k < C; k++){
                sum[i][j][k] = heap[i][j][k];
                if (j > 0)
                    sum[i][j][k] += sum[i][j - 1][k];
                if (k > 0)
                    sum[i][j][k] += sum[i][j][k - 1];
                if (j > 0 && k > 0)
                    sum[i][j][k] -= sum[i][j - 1][k - 1];
            }
}

long long Kadane(){
    long long retval = heap[0][0][0];
    for (int j = 0; j < B; j++)
        for (int k = 0; k < C; k++)
            for (int l = j; l < B; l++)
                for (int p = k; p < C; p++){
                    long long best = 0;
                    for (int i = 0; i < A; i++){
                        if (best < 0)
                            best = 0;
                        long long local_sum = sum[i][l][p];
                        if (j > 0)
                            local_sum -= sum[i][j - 1][p];
                        if (k > 0)
                            local_sum -= sum[i][l][k - 1];
                        if (j > 0 && k > 0)
                            local_sum += sum[i][j - 1][k - 1];
                        best += local_sum;
                        if (best > retval)
                            retval = best;
            }
        }
    return retval;
}

int main(){
    int T;
    scanf("%d", &T);
    bool first_case = true;
    while (T--){
        if (first_case)
            first_case = false;
        else
            printf("\n");
        scanf("%d %d %d", &A, &B, &C);
        for (int i = 0; i < A; i++)
            for (int j = 0; j < B; j++)
                for (int k = 0; k < C; k++)
                    scanf("%lld", &heap[i][j][k]);
        preprocessing();
        printf("%lld\n", Kadane());
    }
    return 0;
}
