#include <bits/stdc++.h>

using namespace std;

int main() {
    printf("PERFECTION OUTPUT\n");
    int N;
    while (scanf("%d", &N) && N) {
        printf("%5d  ", N);
        int sum = 0;
        for (int i = 2; i <= N; i++)
            if (N % i == 0)
                sum += N / i;
        if (sum == N)
            printf("PERFECT\n");
        else if (sum < N)
            printf("DEFICIENT\n");
        else
            printf("ABUNDANT\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
