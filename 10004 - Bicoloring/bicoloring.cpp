#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int n;
    while (scanf("%d", &n) && n){
        int l;
        scanf("%d", &l);
        vector<vector<int>> adjList(n);
        for (int i = 0; i < l; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> color(n, -1);
        queue<int> q;
        q.push(0);
        color[0] = 0;
        bool bipartite = true;
        while (bipartite && !q.empty()){
            int u = q.front();
            q.pop();
            for (int dest: adjList[u]){
                if (color[dest] == -1){
                    color[dest] = 1 - color[u];
                    q.push(dest);
                }
                else if (color[dest] == color[u]){
                    bipartite = false;
                    break;
                }
            }
        }

        if (bipartite)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
