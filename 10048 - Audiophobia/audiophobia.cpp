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
};

vector<vector<pair<int, int>>> adjList;
vector<pair<int, pair<int, int>>> edgeList;
int C, S, Q;
DisjointSets dsets;
vector<bool> visited;
int answer;

bool DFS(int node, int dest){
    visited[node] = true;
    if (node == dest)
        return true;

    for (pair<int, int>& it: adjList[node]){
        int next = it.first, d = it.second;
        if (!visited[next] && DFS(next, dest)){
            answer = max(d, answer);
            return true;
        }
    }
    return false;
}

int main(){
    int test_case = 0; 
    while (scanf("%d %d %d", &C, &S, &Q) && (C || S || Q)){
        test_case++;
        if (test_case > 1)
            printf("\n");
        printf("Case #%d\n", test_case);
        adjList.assign(C, vector<pair<int, int>>());
        edgeList.assign(S, pair<int, pair<int, int>>());
        dsets.assign(C);

        for (int i = 0; i < S; i++){
            int c1, c2, d;
            scanf("%d %d %d", &c1, &c2, &d);
            c1--, c2--;
            edgeList[i] = {d, {c1, c2}};
        }

        sort(edgeList.begin(), edgeList.end());

        for (auto it: edgeList){
            int d = it.first, u = it.second.first, v = it.second.second;
            if (!dsets.isSameSet(u, v)){
                adjList[u].push_back({v, d});
                adjList[v].push_back({u, d});
                dsets.setUnion(u, v);
            }
        }

        for (int i = 0; i < Q; i++){
            int c1, c2;
            answer = 0;
            visited.assign(C, false);
            scanf("%d %d", &c1, &c2);
            c1--, c2--;
            if (DFS(c1, c2))
                printf("%d\n", answer);
            else
                printf("no path\n");
        }
    }
    return 0;
}
