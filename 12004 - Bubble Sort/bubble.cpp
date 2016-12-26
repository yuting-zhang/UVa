#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<long long> solution(100000);
    solution[0] = 0;
    for (int i = 1; i < 100000; i++)
        solution[i] = solution[i - 1] + i;
    int T, n;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++) {
        scanf("%d", &n);
        printf("Case %d: ", cases);
        if (solution[n - 1] % 2 == 0)
            printf("%lld\n", solution[n - 1] / 2);
        else
            printf("%lld/2\n", solution[n - 1]);
    }

    return 0;
}
