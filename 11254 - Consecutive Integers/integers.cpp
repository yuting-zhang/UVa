#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    while (scanf("%d", &N) && N != -1) {
        int start = -1, range = -1;
        for (int r = sqrt(2 * N); r >= 1; r--) {
            int a = (2 * N + r - r * r) / (2 * r);
            if (2 * a * r + r * r - r == 2 * N) {
                start = a;
                range = r;
                break;
            }
        }
        printf("%d = %d + ... + %d\n", N, start, start + range - 1);
    }
    return 0;
}
