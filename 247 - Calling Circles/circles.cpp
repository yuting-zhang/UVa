#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
map<string, int> mapper;
vector<pair<string, vector<int>>> adjList;

vector<int> dfs_num, dfs_low;
vector<int> SCC;

vector<bool> inStack;

int nodeCount = 0;

void Tarjan(int node){
    dfs_num[node] = dfs_low[node] = nodeCount++;
    inStack[node] = true;
    SCC.push_back(node);

    for (int dest: adjList[node].second){
        if (dfs_num[dest] == -1)
            Tarjan(dest);
        if (inStack[dest])
            dfs_low[node] = min(dfs_low[node], dfs_low[dest]);
    }

    if (dfs_low[node] == dfs_num[node]){
        while (true){
            int u = SCC.back();
            SCC.pop_back();
            inStack[u] = false;
            printf("%s", adjList[u].first.c_str());
            if (u != node)
                printf(", ");
            else{
                printf("\n");
                break;
            }
        }
    }
}

int main(){
    int dataset = 0;
    while (scanf("%d %d", &n, &m) && n){
        dataset++;
        if (dataset > 1)
            printf("\n");
        printf("Calling circles for data set %d:\n", dataset);
        mapper.clear();
        adjList.assign(n, pair<string, vector<int>>());
        int personCount = 0;
        for (int i = 0; i < m; i++){
            string name1, name2;
            cin >> name1 >> name2;
            if (mapper.find(name1) == mapper.end()){
                mapper[name1] = personCount;
                adjList[personCount++].first = name1;
            }
            if (mapper.find(name2) == mapper.end()){
                mapper[name2] = personCount;
                adjList[personCount++].first = name2;
            }
            adjList[mapper[name1]].second.push_back(mapper[name2]);
        }

        dfs_num.assign(n, -1);
        dfs_low.assign(n, 0);
        SCC.clear();
        inStack.assign(n, false);
        nodeCount = 0;
        for (int i = 0; i < n; i++)
            if (dfs_num[i] == -1)
                Tarjan(i);
    }
}
