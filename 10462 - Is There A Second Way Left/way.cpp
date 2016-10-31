#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

class DisjointSets {
public:
    void addelements(int num) {
        while (num--)
            s.push_back(-1);
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

typedef pair<int, pair<pair<int, int>, bool>> iiib;

pair<int, vector<int>> Kruskal(int v, const vector<iiib>& edgeList) {
    DisjointSets ds;
    ds.addelements(v);
    int cost = 0, chosen = 0;
    vector<int> edges;
    for (int i = 0; i < edgeList.size(); i++) {
        if (edgeList[i].second.second) {
            int a = edgeList[i].second.first.first;
            int b = edgeList[i].second.first.second;
            if (ds.find(a) != ds.find(b)) {
                edges.push_back(i);
                ds.setunion(a, b);
                cost += edgeList[i].first;
                chosen++;
                if (chosen == v - 1)
                    break;
            }
        }
    }
    if (chosen < v - 1)
        return {-1, edges};
    else
        return {cost, edges};
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        printf("Case #%d : ", tc);
        int v, e;
        scanf("%d %d", &v, &e);
        int indexer = 0;
        unordered_map<int, int> mapper;
        vector<iiib> edgeList(e);

        for (int i = 0; i < e; i++) {
            int start, end, cost;
            scanf("%d %d %d", &start, &end, &cost);
            if (mapper.count(start) == 0)
                mapper[start] = indexer++;
            if (mapper.count(end) == 0)
                mapper[end] = indexer++;
            edgeList[i]= {cost, {{mapper[start], mapper[end]}, true}};
        }

        sort(edgeList.begin(), edgeList.end());
        auto best = Kruskal(v, edgeList);
        if (best.first == -1)
            printf("No way\n");
        else {
            int second = -1;
            for (int edge: best.second) {
                edgeList[edge].second.second = false;
                auto result = Kruskal(v, edgeList);
                if (result.first != -1) {
                    if (second == -1)
                        second = result.first;
                    else
                        second = min(second, result.first);
                }
                edgeList[edge].second.second = true;
            }
            if (second == -1)
                printf("No second way\n");
            else
                printf("%d\n", second);
        }
    }
}
