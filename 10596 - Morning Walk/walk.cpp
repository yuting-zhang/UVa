#include <bits/stdc++.h>

using namespace std;

void Euler_tour(int u, list<int> &tour, list<int>::iterator it, 
                vector<vector<pair<int, bool>>> &adj_list) {
    for (auto &edge : adj_list[u]) {
        if (edge.second) {
            int v = edge.first;
            edge.second = false;
            for (auto &bi_edge : adj_list[v]) 
                if (bi_edge.first == u && bi_edge.second) {
                    bi_edge.second = false;
                    break;
                }
            Euler_tour(v, tour, tour.insert(it, u), adj_list);
        }
    }
}

int main() {
    int N, R;
    while (scanf("%d %d", &N, &R) == 2) {
        vector<int> degree(N);
        vector<vector<pair<int, bool>>> adj_list(N);

        int start = -1;
        for (int i = 0; i < R; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (start == -1)
                start = u;
            adj_list[u].push_back({v, true});
            adj_list[v].push_back({u, true});
            degree[u]++;
            degree[v]++;
        }

        bool Euler = R != 0;

        if (Euler) {
            for (int num : degree)
                if (num % 2) {
                    Euler = false;
                    break;
                }
        }

        if (Euler) {
            list<int> tour;
            Euler_tour(start, tour, tour.begin(), adj_list);
            Euler = tour.size() == R;
        }

        printf("%s\n", Euler ? "Possible" : "Not Possible");
    }
    return 0;
}
