#include <bits/stdc++.h>

using namespace std;

long long pow(long long base, long long exp, long long MOD) {
    if (exp == 0)
        return 1;

    if (exp % 2 == 0) {
        long long result = pow(base, exp / 2, MOD) % MOD;
        return result * result % MOD;
    }
    else  {
        long long result = pow(base, exp / 2, MOD) % MOD;
        return base * result * result % MOD;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++) {
        long long n, K, MOD;
        scanf("%lld %lld %lld", &n, &K, &MOD);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long num;
            scanf("%lld", &num);
            sum += num;
            sum %= MOD;
        }

        long long solution = pow(n, K - 1, MOD);
        solution = solution * sum * (K % MOD) % MOD;
        printf("Case %d: %lld\n", cases, solution);
    }
    return 0;
}
