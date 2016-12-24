#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) == 2) {
        int sum = 0, butts = 0;
        while (n) {
            sum += n;
            butts += n;
            n = butts / k;
            butts %= k;
        }
        printf("%d\n", sum);
    }
    return 0;
}
