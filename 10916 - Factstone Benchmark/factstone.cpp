#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> benchmark(21);

    double power = 4;
    int exp = 2;
    int power_hidden = 0;

    double factorial = 1;
    int fact_num = 1;
    int factorial_hidden = 0;

    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < exp; j++) {
            power *= 2;
            while (power > 1e30) {
                power_hidden++;
                power /= 10;
            }
        }

        exp *= 2;

        while (true) {
            int power_digits = 1 + (int)log10(power) + power_hidden;
            int fact_digits = 1 + (int)log10(factorial) + factorial_hidden;

            if (fact_digits > power_digits || 
                fact_digits == power_digits && factorial >= power) {
                benchmark[i] = fact_num - 1;
                break;
            }

            factorial *= ++fact_num;
            while (factorial > 1e30) {
                factorial_hidden++;
                factorial /= 10;
            }
        }
    }

    int y;
    while (scanf("%d", &y) && y) 
        printf("%d\n", benchmark[(y - 1960) / 10]);

    return 0;
}
