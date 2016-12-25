#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    while (scanf("%d", &N) && N >= 0) {
        int solution = -1;

        for (int i = ceil(sqrt(N)); i > 0 && solution == -1; i--) {
            bool good = true;
            int remain = N;
            for (int j = 0; j < i; j++) {
                if (remain % i != 1) {
                    good = false;
                    break;
                }
                remain = remain / i * (i - 1);
            }
            if (good && remain % i == 0)
                solution = i;
        }
        printf("%d coconuts, ", N);
        if (solution > 0) 
            printf("%d people and 1 monkey\n", solution);
        else
            printf("no solution\n");
    }

    return 0;
}
