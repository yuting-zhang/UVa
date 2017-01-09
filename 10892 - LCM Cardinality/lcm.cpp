#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    long long N;
    while (scanf("%lld", &N) && N) {
        vector<long long> factors;
        for (int i = 1; i < sqrt(N); i++) {
            if (N % i == 0) {
                factors.push_back(i);
                factors.push_back(N / i);
            }
        }
        if (pow((int)sqrt(N), 2) == N)
            factors.push_back(sqrt(N));

        sort(factors.begin(), factors.end());

        int cardinality = 0;
        for (int i = 0; i < factors.size(); i++)
            for (int j = i; j < factors.size(); j++)
                if (lcm(factors[j], factors[i]) == N)
                    cardinality++;

        printf("%lld %d\n", N, cardinality);
    }

    return 0;
}
