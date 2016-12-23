#include <bits/stdc++.h>

using namespace std;

void euler_cycle(int u, list<pair<int, int>> &euler, 
                 list<pair<int, int>>::iterator it, 
                 vector<vector<pair<int, bool>>> &adj_list) {
    for (auto &edge : adj_list[u]) {
        if (edge.second) {
            int v = edge.first;
            edge.second = false;
            for (auto &bi_edge: adj_list[v])
                if (bi_edge.first == u && bi_edge.second) {
                    bi_edge.second = false;
                    break;
                }
            euler_cycle(v, euler, euler.insert(it, {v, u}), adj_list);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int cases = 0; cases < T; cases++) {
        if (cases)
            printf("\n");
        printf("Case #%d\n", cases + 1);

        int N;
        scanf("%d", &N);
        vector<vector<pair<int, bool>>> adj_list(50);
        vector<int> degree(50);

        for (int i = 0; i < N; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj_list[u - 1].push_back({v - 1, true});
            adj_list[v - 1].push_back({u - 1, true});
            degree[u - 1]++;
            degree[v - 1]++;
        }

        bool good = true;
        int start = -1;
        for (int i = 0; i < 50; i++) {
            if (degree[i] % 2) {
                good = false;
                break;
            }
            else if (degree[i] && start == -1)
                start = i;
        }
                
        if (!good) {
            printf("some beads may be lost\n");
            continue;
        }

        list<pair<int, int>> euler;
        euler_cycle(start, euler, euler.begin(), adj_list);

        for (const auto &item : euler)
            printf("%d %d\n", item.first + 1, item.second + 1);
    }
    return 0;   
}
