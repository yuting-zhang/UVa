#include <bits/stdc++.h>

using namespace std;

long long H(int n) {
    if (n <= 0)
        return 0;

    long long res = 0;
    long long prev = -1;
    for (int i = 1; i <= sqrt(n); i++)  {
        long long curr = n / i;
        res += curr;
        if (prev != -1)
            res += (prev - curr) * (i - 1);
        prev = curr;
    }

    res += (int)sqrt(n) * (prev - (int)sqrt(n));

    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", H(n));
    }
    return 0;
}
