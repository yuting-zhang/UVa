#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cases = 0; cases < T; cases++) {
        int count[105] = {0};
        int n;
        scanf("%d", &n);
        bool good = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int num;
                scanf("%d", &num);
                if (++count[num] > n)
                    good = false;
            }
            printf("Case %d: %s\n", cases + 1, good ? "yes" : "no");
    }
    return 0;
}
