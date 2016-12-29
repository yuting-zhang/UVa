#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) && n != -1) {
        n++;
        vector<int> coeffs(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &coeffs[i]);

        for (int i = coeffs.size() - 1; i > k - 1; i--) {
            if (coeffs[i] == 0)
                continue;
            coeffs[i - k] -= coeffs[i];
        }

        int index = min(k - 1, (int)coeffs.size() - 1);
        while (index >= 0 && coeffs[index] == 0)
            index--;
        if (index < 0)
            printf("0\n");
        else {
            printf("%d", coeffs[0]);
            for (int i = 1; i <= index; i++)
                printf(" %d", coeffs[i]);
            printf("\n");
        }
    }

    return 0;
}
