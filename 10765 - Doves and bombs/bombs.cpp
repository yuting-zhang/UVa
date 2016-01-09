#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n, m;
int rootChildren, root, nodeCount;

vector<int> parent, dfs_low, dfs_num;
vector<vector<int>> adjList;

vector<pair<int, int>> target;

void DFSArticulationPoint(int node){
    dfs_low[node] = dfs_num[node] = nodeCount++;    

    for (int dest: adjList[node]){
        if (dfs_num[dest] == -1){
            if (node == root)
                rootChildren++;
            parent[dest] = node;
            DFSArticulationPoint(dest);

            if (dfs_low[dest] >= dfs_num[node])
                target[node].first++;
            dfs_low[node] = min(dfs_low[node], dfs_low[dest]);
        }
        else if (parent[node] != dest)
            dfs_low[node] = min(dfs_low[node], dfs_num[dest]);
    }
}

int main(){
    while (scanf("%d %d", &n, &m) && n){
        int x, y;
        adjList.assign(n, vector<int>());

        while (scanf("%d %d", &x, &y) && x >= 0 && y >= 0){
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }

        parent.assign(n, 0);
        dfs_low.assign(n, 0);
        dfs_num.assign(n, -1);
        target.clear();
        target.reserve(n);
        for (int i = 0; i < n; i++)
            target.push_back(make_pair(0, i));

        nodeCount = 0;
        root = 0;
        rootChildren = 0;
        DFSArticulationPoint(0);

        target[root] = {0, rootChildren - 1};

        for (int i = 0; i < n; i++)
            target[i].first++;

        sort(target.begin(), target.end(), [](const pair<int,int>& lhs, const pair<int, int>& rhs)
            { if (lhs.first > rhs.first) return true; 
              else if (lhs.first == rhs.first) return lhs.second < rhs.second;
              return false;});

        for (int i = 0; i < m; i++)
            printf("%d %d\n", target[i].second, target[i].first);    
        printf("\n");
    }
    return 0;
}
