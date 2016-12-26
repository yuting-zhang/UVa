#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, N;
    scanf("%d", &T);
    bool first = true;
    while (T--) {
        if (first)
            first = false;
        else
            printf("\n");
        scanf("%d", &N);

        double solution = 0;
        if (N == 0)
            solution = 0;
        else if (N == 1)
            solution = 0;
        else if (N == 2)
            solution = 4;
        else 
            solution = (N - 2) * (N - 2) * sqrt(2) + N * N - (N - 2) * (N - 2);
        printf("%.3f\n", solution);
    }
    return 0; 
}
