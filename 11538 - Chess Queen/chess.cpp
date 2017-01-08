#include <bits/stdc++.h>

using namespace std;

int main() {
    long long M, N;
    while (scanf("%lld %lld", &M, &N) && M && N) {
        long long result = 0;
        if (M < N)
            swap(M, N);
        result += M * N * (N - 1);
        result += N * M * (M - 1);
        for (long long i = 2; i < N; i++)
            result += 2 * 2 * i * (i - 1);
        result += 2 * (M - N + 1) * N * (N - 1);
        printf("%lld\n", result);
    }

    return 0;
}
