#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, R, T = 0;
    while (scanf("%d %d", &R, &N) && N) {
        printf("Case %d: ", ++T);
        if (26 * N + N < R)
            printf("impossible\n");
        else 
            printf("%d\n", R % N == 0 ? R / N - 1 : R / N);
    }

    return 0; 
}
