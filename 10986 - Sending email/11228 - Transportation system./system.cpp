#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

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

    bool isSameSet(int a, int b){
        return find(a) == find(b);
    }
    
    int numOfSets(){
        return count;
    }

    void setunion(int a, int b){
        int root1 = find(a), root2 = find(b);
        if (root1 != root2){
            int newSize = s[root1] + s[root2];
            if (s[root1] <= s[root2]){
                s[root2] = root1;
                s[root1] = newSize;
            }
            else{
                s[root1] = root2;
                s[root2] = newSize;
            }
            count--;
        }
    }
private:
    vector<int> s;
    int count;
};

int n, r;
vector<pair<int, pair<int, int>>> edgeList;
DisjointSets stateSets, MSTSets;

int main(){
    int T, data_set = 0;
    scanf("%d", &T);
    while (T--){
        data_set++;
        scanf("%d %d", &n, &r);
        r = pow(r, 2);

        vector<int> x(n), y(n);
        stateSets.assign(n);

        for (int i = 0; i < n; i++)
            scanf("%d %d", &x[i], &y[i]);

        edgeList.clear();
        edgeList.reserve(n * n);
        
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++){
                int dist = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
                edgeList.push_back({dist, {i, j}});
                if (dist <= r)
                    stateSets.setunion(i, j);
            }
        sort(edgeList.begin(), edgeList.end());

        MSTSets.assign(n);
        int edgeCount = 0;
        double road = 0, railroad = 0;
        for (auto it: edgeList){
            int dest = it.first, u = it.second.first, v = it.second.second;
            if (!MSTSets.isSameSet(u, v)){
                MSTSets.setunion(u, v);

                if (stateSets.isSameSet(u, v))
                    road += sqrt(dest);
                else
                    railroad += sqrt(dest);
                edgeCount++;
                if (edgeCount == n - 1)
                    break;
            }

        }

        printf("Case #%d: %d %.0f %.0f\n", data_set, stateSets.numOfSets(), road, railroad);
    }
}
