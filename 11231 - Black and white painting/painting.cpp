#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, c;
    while (scanf("%d %d %d", &n, &m, &c) && n) {
        long long solution = n * m / 2;
        if (n * m % 2 == 1 && c == 1) 
            solution += 1;

        bool first_white = false;
        if ((n + m) % 2 == 0 && c == 1)
            first_white = true;

        long long left_white = 7 * n / 2;
        long long upper_white = 7 * m / 2;
        long long upper_left_white = 7 * 7 / 2;

        if (n % 2 == 1 && first_white)
            left_white++;
        if (m % 2 == 1 && first_white)
            upper_white++;
        if (first_white)
            upper_left_white++;

        solution = solution - left_white - upper_white + upper_left_white;

        printf("%lld\n", solution);
    }
    return 0;
}
