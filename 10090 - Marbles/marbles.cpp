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
    long long n;
    while (scanf("%lld", &n) && n) {
        long long c1, n1, c2, n2;
        scanf("%lld %lld %lld %lld", &c1, &n1, &c2, &n2);

        bool flipped = false;
        if (1.0 * c1 / n1 > 1.0 * c2 / n2) {
            swap(c1, c2);
            swap(n1, n2);
            flipped = true;
        }

        extended_Euclid(n1, n2);

        if (n % d != 0) {
            printf("failed\n");
            continue;
        }


        x *= n / d;
        y *= n / d;

        long long lower = ceil(1.0 * -x * d / n2), 
                  upper = floor(1.0 * y * d / n1);

        if (lower > upper) {
            printf("failed\n");
            continue;
        }

        x += n2 / d * upper;
        y -= n1 / d * upper;

        if (flipped)
            swap(x, y);
        printf("%lld %lld\n", x, y);
    }
    return 0;
}
