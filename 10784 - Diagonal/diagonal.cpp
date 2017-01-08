#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N;
    int cases = 0;
    while (scanf("%lld", &N) && N) {
        double a = 1.0, b = -3.0, c = -2 * N;
        long long n = ceil((-b + pow(b * b - 4 * a * c, 0.5)) / (2 * a));
        printf("Case %d: %lld\n", ++cases, n);
    }
    return 0;
}
