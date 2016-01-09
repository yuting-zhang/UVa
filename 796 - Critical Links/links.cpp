#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

int N;
vector<vector<int>> adjList;
vector<int> dfs_num, dfs_low, parent;
vector<pair<int, int>> bridge;

int nodeCount;

void DFSBridge(int node){
    dfs_num[node] = dfs_low[node] = nodeCount++;
    for (int dest: adjList[node]){
        if (dfs_num[dest] == -1){
            parent[dest] = node;
            DFSBridge(dest);

            if (dfs_low[dest] > dfs_num[node]){
                if (node < dest)
                    bridge.push_back(make_pair(node, dest));
                else
                    bridge.push_back(make_pair(dest, node));
            }
            dfs_low[node] = min(dfs_low[node], dfs_low[dest]);
        }
        else if (parent[node] != dest)
            dfs_low[node] = min(dfs_low[node], dfs_num[dest]);
    }
}

int main(){
    while (scanf("%d", &N) == 1){
        adjList.assign(N, vector<int>());
        for (int i = 0; i < N; i++){
            int u, no;
            scanf("%d (%d)", &u, &no);
            for (int j = 0; j < no; j++){
                int v;
                scanf("%d", &v);
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }
        dfs_num.assign(N, -1);
        dfs_low.assign(N, 0);
        parent.assign(N, 0);
        bridge.clear();
        
        for (int i = 0; i < N; i++)
            if (dfs_num[i] == -1)
                DFSBridge(i);
        
        sort(bridge.begin(), bridge.end());
        printf("%lu critical links\n", bridge.size());
        for (auto& it: bridge)
            printf("%d - %d\n", it.first, it.second);
        printf("\n");
    }
    return 0;
}
