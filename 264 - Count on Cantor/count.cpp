#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int layer = sqrt(2 * n);
        if ((1 + layer) * layer / 2 < n)
            layer++;

        int remain = n - (1 + layer - 1) * (layer - 1) / 2;
        if (layer % 2 == 0) 
            printf("TERM %d IS %d/%d\n", n, remain, layer - remain + 1);
        else
            printf("TERM %d IS %d/%d\n", n, layer - remain + 1, remain);
    }
    return 0;
}
