#include <bits/stdc++.h>

using namespace std;

long long memo[25][24 * 150 + 5];

long long solve(int n, int x) {
    if (x < 0)
        return 0;

    if (memo[n][x] != -1)
        return memo[n][x];

    long long &value = memo[n][x];

    if (n == 0)
        return value = (x == 0 ? 1 : 0);

    value = 0;
    for (int i = 1; i <= 6; i++)
        value += solve(n - 1, x - i);
    return value; 
}

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    int n, x;
    while (scanf("%d %d", &n, &x) && n) {
        memset(memo, -1, sizeof memo); 
        long long numerator = 0;
        for (int i = x; i <= 6 * n; i++)
            numerator += solve(n, i);

        if (numerator == 0) {
            printf("0\n");
            continue;
        }
        long long denominator = pow(6, n);
        if (numerator == denominator) {
            printf("1\n");
            continue;
        }
        long long result = gcd(numerator, denominator);
        printf("%lld/%lld\n", numerator / result, denominator / result);
    }
    return 0;
}
