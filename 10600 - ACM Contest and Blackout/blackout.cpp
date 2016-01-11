#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class DisjointSets{
public:
    void assign(int n){
        s.assign(n, -1);
    }
    int find(int elem){
        return s[elem] < 0 ? elem : s[elem] = find(s[elem]);
    }
    bool isSameSet(int elem1, int elem2){
        return find(elem1) == find(elem2);
    }
    void setUnion(int elem1, int elem2){
        int root1 = find(elem1), root2 = find(elem2);
        if (root1 != root2){
            int newSize = s[root1] + s[root2];
            if (s[root1] < s[root2]){
                s[root2] = root1;
                s[root1] = newSize;
            }
            else{
                s[root1] = root2;
                s[root2] = newSize;
            }
        }
    }
private:
    vector<int> s;
};

int N, M;
vector<pair<int, pair<int, int>>> edgeList;
vector<bool> enabled;
vector<int> MST;

int Kruskal(bool initial){
    int cost = 0;
    DisjointSets dsets;
    dsets.assign(N);
    int edgeCount = 0;
    for (int i = 0; i < M; i++){
        if (!enabled[i])
            continue;

        auto& edge = edgeList[i];
        int w = edge.first, u = edge.second.first, v = edge.second.second;
        if (!dsets.isSameSet(u, v)){
            cost += w;
            if (initial)
                MST[edgeCount] = i;
            edgeCount++;
            dsets.setUnion(u, v);
            if (edgeCount == N - 1)
                break;
        }
    }
    if (edgeCount != N - 1)
        cost = (1 << 30);
    return cost;
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d %d", &N, &M);
        edgeList.assign(M, pair<int, pair<int, int>>());
        enabled.assign(M, true);
        for (int i = 0; i < M; i++){
            int A, B, C;
            scanf("%d %d %d", &A, &B, &C);
            edgeList[i] = {C, {A - 1, B - 1}};
        }
        sort(edgeList.begin(), edgeList.end());
        
        MST.assign(N - 1, 0);
        int minimum = Kruskal(true);
        int second = 1 << 30;
        for (int i = 0; i < MST.size(); i++){
            enabled[MST[i]] = false;
            second = min(second, Kruskal(false));
            enabled[MST[i]] = true;
        }
        printf("%d %d\n", minimum, second);
    }
}
