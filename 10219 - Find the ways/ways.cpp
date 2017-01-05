#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) == 2) {
        double comb = 1;
        long long digits = 0;

        int temp = k;
        for (int i = n; i > n - k; i--) {
            comb *= i;
            if (temp) {
                comb /= temp;
                temp--;
            }
            while (comb > 1e20) {
                comb /= 10;
                digits++;
            }
        }

        while (temp) {
            comb /= temp;
            temp--;
        }

        digits += log10(comb) + 1;
        printf("%lld\n", digits);
    }
    return 0;
}
