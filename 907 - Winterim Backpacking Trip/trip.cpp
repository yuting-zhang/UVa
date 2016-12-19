#include <bits/stdc++.h>

using namespace std;

typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;


long long solve(int camp, int remain, vvll &memo, const vll &dist) {
    if (camp == 0 && remain == 0)
        return 0;

    if (remain == 0 || camp == 0)
        return INT_MAX;

    if (memo[camp][remain] != -1)
        return memo[camp][remain];

    for (int prev = remain - 1; prev < camp; prev++) {
        long long result = solve(prev, remain - 1, memo, dist);
        result = max(result, dist[camp] - dist[prev]);

        if (memo[camp][remain] == -1 || memo[camp][remain] > result)
            memo[camp][remain] = result;
    }

    return memo[camp][remain];
}

int main() {
    int N, K;
    while (cin >> N >> K) {
        N += 2;
        K += 1;

        vector<long long> dist(N);
        for (int i = 1; i < N; i++) {
            cin >> dist[i];
            dist[i] += dist[i - 1];
        }

        vvll memo(N, vll(K + 1, -1));

        cout << solve(N - 1, K, memo, dist) << "\n";
    }

    return 0;
}
