#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

int main(){
    int V;
    while (scanf("%d", &V) && V){
        vector<vector<int>> adjList(V);
        int a, b;
        while (scanf("%d %d", &a, &b) && a && b){
            adjList[a - 1].push_back(b - 1);
            adjList[b - 1].push_back(a - 1);
        }
        vector<int> color(V, -1);

        bool bipartite = true;
        for (int i = 0; bipartite && i < V; i++)
            if (color[i] == -1){
                queue<int> q;
                q.push(i);
                color[i] = 0;
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
            }
        if (bipartite)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
