#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int m, n, r, c;
        scanf("%d %d %d %d", &m, &n, &r, &c);
        int piles[4];
        piles[0] = r;
        piles[1] = m - 1 - r;
        piles[2] = c;
        piles[3] = n - 1 - c;
        int result = piles[0];
        for (int i = 1; i < 4; i++)
            result ^= piles[i];
        if (result)
            printf("Gretel\n");
        else
            printf("Hansel\n");
    }
    return 0;
}
