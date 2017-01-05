#include <bits/stdc++.h>

using namespace std;

int main() {
    int period[] = {60, 300, 1500, 15000};
    int mod[] = {10, 100, 1000, 10000};
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, n, m;
        scanf("%d %d %d %d", &a, &b, &n, &m);
        m--;
        int seq[period[m]] = {a % mod[m], b % mod[m]};
        for (int i = 2; i < period[m]; i++)
            seq[i] = (seq[i - 1] + seq[i - 2]) % mod[m];

        printf("%d\n", seq[n % period[m]]);  
    }
    return 0;
}
