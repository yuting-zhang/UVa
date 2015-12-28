#include <cstdio>

using namespace std;

int price[110][110];
long long sum[110][110];

int main(){
    int T;
    scanf("%d", &T);
    for (int case_count = 1; case_count <= T; case_count++){
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%d", &price[i][j]);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++){
                sum[i][j] = price[i][j];
                if (j > 0)
                    sum[i][j] += sum[i][j - 1];
            }
        
        int S = 0;
        long long P = 0;
        for (int i = 0; i < M; i++)
            for (int j = i; j < M; j++){
                long long local = 0;
                int begin = 0;
                for (int k = 0; k < N; k++){
                    local += sum[k][j];
                    if (i > 0)
                        local -= sum[k][i - 1];
                    while (local > K && begin <= k){
                        local -= sum[begin][j];
                        if (i > 0)
                            local += sum[begin][i - 1];
                        begin++;
                    }
                    
                    if (begin <= k){
                        int area = (k - begin + 1) * (j - i + 1);
                        if (area > S){
                            S = area;
                            P = local;
                        }
                        else if (area == S && local < P)
                            P = local;
                    }
                }
            }
        printf("Case #%d: %d %lld\n", case_count, S, P);
    }
    return 0;
}
