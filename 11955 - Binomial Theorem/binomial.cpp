#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<long long>> pascal(55, vector<long long>(60, 0));
    pascal[0][0] = 1;
    for (int i = 1; i < 55; i++) {
        pascal[i][0] = pascal[i][i] = 1;
        for (int j = 1; j < i; j++)
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
    }

    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++) {
        char a[100], b[100];
        int power;
        scanf(" (%[a-z]+%[a-z])^%d", a, b, &power);
        printf("Case %d: ", cases);

        for (int i = 0; i <= power; i++) {
            if (i != 0)
                printf("+");

            if (pascal[power][i] != 1)
                printf("%lld*", pascal[power][i]);

            int a_pow = power - i, b_pow = i;
            if (a_pow) {
                printf("%s", a);
                if (a_pow > 1)
                    printf("^%d", a_pow);
            }
            if (a_pow && b_pow)
                printf("*");
            if (b_pow) {
                printf("%s", b);
                if (b_pow > 1)
                    printf("^%d", b_pow);
            }
        }
        printf("\n");
    }

    return 0;
}
