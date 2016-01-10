#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;

vector<vector<int>> adjList;
vector<int> dfs_low, dfs_num, Stack;
vector<bool> inStack;

int nodeCount;
bool isSCC;

void tarjan(int node){
    dfs_low[node] = dfs_num[node] = nodeCount++;
    Stack.push_back(node);
    inStack[node] = true;

    for (int dest: adjList[node]){
        if (dfs_num[dest] == -1)
            tarjan(dest);
        if (inStack[dest])
            dfs_low[node] = min(dfs_low[node], dfs_low[dest]);
    } 

    if (dfs_low[node] == dfs_num[node]){
        int count = 0;
        while (true){
            int u = Stack.back();
            Stack.pop_back();
            inStack[u] = false;
            count++;
            if (u == node)
                break;
        }
        if (count != N)
            isSCC = false;
    }
}

int main(){
    while (scanf("%d %d", &N, &M) && N){
        adjList.assign(N, vector<int>());
        for (int i = 0; i < M; i++){
            int V, W, P;
            scanf("%d %d %d", &V, &W, &P);
            V--, W--;
            adjList[V].push_back(W);
            if (P == 2)
                adjList[W].push_back(V);
        }

        dfs_low.assign(N, 0);
        dfs_num.assign(N, -1);
        Stack.clear();
        inStack.assign(N, false);
        nodeCount = 0;
        isSCC = true;
        tarjan(0);
        if (isSCC)
            printf("1\n");
        else
            printf("0\n");
    }
}
