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
    long long A, B;
    while (scanf("%lld %lld", &A, &B) == 2) {
        extended_Euclid(A, B);         
        printf("%lld %lld %lld\n", x, y ,d);
    }
    return 0;
}
