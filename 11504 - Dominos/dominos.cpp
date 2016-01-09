#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int SCCCount;
vector<int> SCCNumber;

vector<int> dfs_low, dfs_num, Stack;
vector<bool> inStack;
vector<vector<int>> adjList;
int nodeCount;

vector<int> id;

void tarjan(int u){    
    dfs_low[u] = dfs_num[u] = nodeCount++;
    Stack.push_back(u);
    inStack[u] = true;
    
    for (int dest: adjList[u]){
        if (dfs_num[dest] == -1)
            tarjan(dest);
        if (inStack[dest])
            dfs_low[u] = min(dfs_low[u], dfs_low[dest]);
    }

    if (dfs_low[u] == dfs_num[u]){
        SCCCount++;            
        while (true){
            int v = Stack.back();
            Stack.pop_back();
            inStack[v] = false;
            SCCNumber[v] = SCCCount;
            if (v == u)
                break;
        }
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        int n, m;
        scanf("%d %d", &n, &m);
        id.assign(n, 0);
        adjList.assign(n, vector<int>());
        for (int i = 0; i < m; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            x--, y--;
            adjList[x].push_back(y);
            id[y]++;
        }

        dfs_low.assign(n, 0);
        dfs_num.assign(n, -1);
        Stack.clear();
        SCCCount = 0;
        SCCNumber.assign(n, 0);
        inStack.assign(n, false);
        nodeCount = 0;

        for (int i = 0; i < n; i++)
            if (dfs_num[i] == -1)
                tarjan(i);

        int answer = 0;

        vector<bool> valid(SCCCount, true);

        for (int i = 0; i < n; i++)
            for (int dest: adjList[i])
                if (SCCNumber[dest] != SCCNumber[i])
                    valid[SCCNumber[dest] - 1] = false;
        for (int i = 0; i < SCCCount; i++)
            if (valid[i])
                answer++;

        printf("%d\n", answer);
    }
    return 0;
}
