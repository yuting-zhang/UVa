#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> adjList;

int nodeCount, rootChild, root;
vector<int> dfs_num, dfs_low, parent, artyPoint;

void articulationPoint(int node){
    dfs_num[node] = dfs_low[node] = nodeCount++;

    for (int dest: adjList[node]){
        if (dfs_num[dest] == -1){
            if (node == root)
                rootChild++;

            parent[dest] = node;
            articulationPoint(dest);
            if (dfs_low[dest] >= dfs_num[node])
                artyPoint[node] = true;
            dfs_low[node] = min(dfs_low[node], dfs_low[dest]);
        }
        else if (dest != parent[node])
            dfs_low[node] = min(dfs_low[node], dfs_num[dest]);
    }
}

int main(){
    while (scanf("%d\n", &N) && N){
        adjList.assign(N, vector<int>());
        string line;
        while (getline(cin, line) && line != "0"){
            istringstream sin(line);
            int u;
            sin >> u;
            int v;
            while (sin >> v){
                adjList[u - 1].push_back(v - 1);
                adjList[v - 1].push_back(u - 1);
            }
        }    

        nodeCount = rootChild = 0;
        artyPoint.assign(N, false);
        dfs_num.assign(N, -1);
        dfs_low.assign(N, 0);
        parent.assign(N, 0);
        
        for (int i = 0; i < N; i++)
            if (dfs_num[i] == -1){
                root = i;
                articulationPoint(i);
                artyPoint[i] = (rootChild > 1);
            }

        int answer = 0;
        for (int i = 0; i < N; i++)
            if (artyPoint[i])
                answer++;
        printf("%d\n", answer);
    }
    return 0;
}
