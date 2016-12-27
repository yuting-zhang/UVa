#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    while (scanf("%d", &N) && N) {
        int layer = sqrt(N);
        if (layer * layer < N)
            layer++;

        int remain = N - (layer - 1) * (layer - 1);

        if (layer % 2 == 0) {
            if (remain < layer) 
                printf("%d %d\n", remain, layer);
            else 
                printf("%d %d\n", layer, layer - (remain - layer));
        }
        else {
            if (remain < layer) 
                printf("%d %d\n", layer, remain);
            else 
                printf("%d %d\n", layer - (remain - layer), layer);
        }
    }
    return 0;
}
