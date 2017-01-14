#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    while (scanf("%lld", &n) == 1) {
        int low = 9;
        int digits[10] = {0};
        long long temp = n;
        while (temp) {
            int digit = temp % 10;
            if (digit)
                low = min(low, digit);
            digits[digit]++;
            temp /= 10;
        }

        long long big = 0;
        for (int i = 9; i >= 0; i--)
            for (int j = 0; j < digits[i]; j++)
                big = big * 10 + i;
        long long small = low;
        digits[low]--;
        for (int i = 0; i <= 9; i++)
            for (int j = 0; j < digits[i]; j++)
                small = small * 10 + i;
        printf("%lld - %lld = %lld = 9 * %lld\n", big, small, big - small,
                (big - small) / 9);
    }
    return 0;
}
