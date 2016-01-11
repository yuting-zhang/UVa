#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

class DisjointSets{
public:
    void assign(int n){
        s.assign(n, -1);
        count = n;
    }
    int find(int elem){
        return s[elem] < 0 ? elem : s[elem] = find(s[elem]);
    }
    bool isSameSet(int elem1, int elem2){
        return find(elem1) == find(elem2);
    }
    int numOfSets(){
        return count;
    }
    void setUnion(int elem1, int elem2){
        int root1 = find(elem1), root2 = find(elem2);
        if (root1 != root2){
            int newSize = s[root1] + s[root2];
            count--;
            if (s[root1] <= s[root2]){
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
    int count;
};

int main(){
    int N;
    scanf("%d", &N);
    while (N--){
        int S, P;
        scanf("%d %d", &S, &P);
        vector<pair<int, pair<int, int>>> edgeList; 
        edgeList.reserve(P * P);
        vector<int> x(P), y(P);
        for (int i = 0; i < P; i++)
            scanf("%d %d", &x[i], &y[i]); 
        for (int i = 0; i < P; i++)
            for (int j = i + 1; j < P; j++)
                edgeList.push_back({pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2),{i , j}}); 
        sort(edgeList.begin(), edgeList.end());
        int it = 0;
        DisjointSets dsets;
        dsets.assign(P);
        for (it = 0; it < edgeList.size(); it++){
            int w = edgeList[it].first, u = edgeList[it].second.first, v = edgeList[it].second.second;
            if (!dsets.isSameSet(u, v)){
                dsets.setUnion(u, v);
                if (dsets.numOfSets() <= S)
                    break;
            }
        }
        printf("%.2f\n", sqrt(edgeList[it].first));
    }
    return 0;
}
