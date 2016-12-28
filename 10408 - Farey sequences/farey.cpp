#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) == 2) {
        vector<pair<double, pair<int, int>>> seq;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++)
                if (gcd(i, j) == 1) 
                    seq.push_back({1.0 * j / i, {j, i}});
        sort(seq.begin(), seq.end());
        printf("%d/%d\n", seq[k - 1].second.first, seq[k - 1].second.second);
    }
    return 0;
}
