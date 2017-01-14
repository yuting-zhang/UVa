#include <bits/stdc++.h>

using namespace std;

long long x, y, d;

void extended_Euclid(long long a, long long b) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    extended_Euclid(b, a % b);
    long long x1 = y, y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--) {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        extended_Euclid(n / k, ceil(1.0 * n / k));
        printf("%lld %lld\n", x * (n / d), y * (n / d));
    }
    return 0;
}
