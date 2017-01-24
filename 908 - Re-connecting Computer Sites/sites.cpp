#include <bits/stdc++.h>

using namespace std;

class DisjointSets {
public:
    void addelements(int num) {
        while (num--) {
            s.push_back(-1);
        }
    }

    int find(int elem) {
        return s[elem] < 0 ? elem : s[elem] = find(s[elem]);
    }

    void setunion(int a, int b) {
        int root1 = find(a), root2 = find(b);
        int newSize = s[root1] + s[root2];
        if (s[root1] <= s[root2]) {
            s[root2] = root1;
            s[root1] = newSize;
        }
        else {
            s[root1] = root2;
            s[root2] = newSize;
        }
    }
private:
    vector<int> s;
};

int main(){
    int N;
    bool first = true;
    while (scanf("%d", &N) == 1) {
        if (first)
            first = false;
        else
            printf("\n");
        vector<pair<long long, pair<int, int>>> edges(N - 1);
        long long original = 0;
        for (int i = 0; i < N - 1; i++) {
            scanf("%d %d %lld", &edges[i].second.first,
                                &edges[i].second.second,
                                &edges[i].first);
            original += edges[i].first;
        }
        int K;
        scanf("%d", &K);
        for (int i = 0; i < K; i++) {
            long long cost;
            int u, v;
            scanf("%d %d %lld", &u, &v, &cost);
            edges.push_back({cost, {u, v}});
        }

        int M;
        scanf("%d", &M); 
        while (M--) {
            long long cost;
            int u, v;
            scanf("%lld %d %d", &cost, &u, &v);
        }
        DisjointSets ds;
        ds.addelements(N);
        sort(edges.begin(), edges.end());

        int selected = 0;
        long long master = 0;
        for (int i = 0; i < edges.size() && selected < N; i++) {
            long long cost = edges[i].first;
            int u = edges[i].second.first - 1;
            int v = edges[i].second.second - 1;
            if (ds.find(u) != ds.find(v)) {
                selected++;
                master += cost;
                ds.setunion(u, v);
            }
        }
        printf("%lld\n%lld\n", original, master);
    }
    return 0;
}
