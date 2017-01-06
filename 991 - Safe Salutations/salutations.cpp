#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    bool first = true;
    while (scanf("%d", &n) == 1) {
        if (first)
            first = false;
        else
            printf("\n");

        long long result = 1;
        for (int i = 2 * n; i > n; i--)
            result *= i;
        for (int i = n; i > 1; i--)
            result /= i;
        result /= n + 1;
        printf("%lld\n", result);
    }
    return 0;
}
