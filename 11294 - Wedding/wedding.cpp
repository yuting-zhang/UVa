#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> adjList;
bool badLuck;
vector<int> dfs_num, dfs_low, stack;
vector<bool> visited;
int counter;

void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = counter++;
    stack.push_back(u);
    visited[u] = true;
    for (int v : adjList[u]){
        if (dfs_num[v] == -1)
            tarjanSCC(v);
        if (badLuck)
            return;
        if (visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_low[u] == dfs_num[u]){
        // Check whether both X and Not X are in the same SCC.
        // If so, then the expression is unsatisfiable.
        vector<bool> SCC(n, false);
        while (true){
            int v = stack.back();
            stack.pop_back();
            visited[v] = false;
            SCC[v] = true;
            // Use xor to conveniently find X or Not X from the other.
            if (SCC[v ^ 1]){
                badLuck = true;
                break;
            }
            if (u == v)
                break;
        }
    }
}

vector<int> toposort;
vector<int> answer;

// Using a variant of DFS to perform topological sort

void dfs(int u){
    dfs_num[u] = 1;
    for (int j : adjList[u])
        if (dfs_num[j] == -1)
            dfs(j);
    toposort.push_back(u);
}

void printSoln(){
    toposort.clear();
    dfs_num.assign(n, -1);
    for (int i = 0; i < n; i++)
        if (dfs_num[i] == -1)
            dfs(i);
    // 1 true, 0 false, -1 unassigned.
    answer.assign(n >> 1, -1);
    for (int i = toposort.size() - 1; i >= 0; i--){
        // If X is before Not X, X is false. Otherwise X is true.
        int u = toposort[i];
        if (u % 2 == 0){
            if (answer[u >> 1] == -1)
                answer[u >> 1] = 0;
        }
        else{
            if (answer[u >> 1] == -1)
                answer[u >> 1] = 1;
        }
    }

    // If the bride is sit on the wrong side, the there is no solution.
    if (answer[0] == false){
        printf("bad luck\n");
        return;
    }
    
    for (int i = 1; i < (n >> 1); i++){
        if (i != 1)
            printf(" ");
        printf("%d%c", i, answer[i] ? 'w' : 'h');
    }
    printf("\n");
}

int main(){
    while (scanf("%d %d", &n, &m) == 2 && (n || m)){
        // Let X be wife sitting on the bride's side, husband sitting on the groom's side.
        // Let Not X be wife sitting on the groom's side, husband sitting on the brides' side.
        
        // Let adjList[i * 2] be X[i], adjList[i * 2 + 1] be Not X[i]
        n <<= 1;
        adjList.assign(n, vector<int>());    
        for (int i = 0; i < m; i++){
            int couple1, couple2;
            char role1, role2;
            scanf("%d%c %d%c", &couple1, &role1, &couple2, &role2);
            couple1 <<= 1;
            couple2 <<= 1;
            
            // Construct graph according to the constraints
            if (role1 == 'w') couple1 ^= 1;
            if (role2 == 'w') couple2 ^= 1;
            
            adjList[couple1].push_back(couple2 ^ 1);
            adjList[couple2].push_back(couple1 ^ 1);
        }

        badLuck = false;
        // Trajan's algorithm to check SCC
        counter = 0;
        dfs_num.assign(n, -1);
        dfs_low.assign(n, 0);
        visited.assign(n, false);
        stack.clear();
        for (int i = 0; !badLuck && i < n; i++)
            if (dfs_num[i] == -1)
                tarjanSCC(i);

        if (badLuck)
            printf("bad luck\n");
        else
            printSoln();
    }
}
