#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N;
    while (scanf("%lld", &N) == 1) {
        int E = 0;
        double power = 1;

        int digits = 1 + log10(N);
        int hidden_digits = 0;

        while (true) {
            while (power > 1e30) {
                hidden_digits++;
                power /= 10;
            }

            int power_digits = 1 + log10(power);
            long long prefix = power / pow(10, power_digits - digits);
            if (power_digits + hidden_digits > 2 * digits) {
                if (prefix == N)
                    break;
            }

            power *= 2;
            E++;
        }
        printf("%d\n", E);
    }
    return 0;
}
