#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        int v, e;
        scanf("%d %d", &v, &e);
        vector<vector<int>> adjList(v);
        for (int i = 0; i < e; i++){
            int f, t;
            scanf("%d %d", &f, &t);
            adjList[f].push_back(t);
            adjList[t].push_back(f);
        }
        
        bool bipartite = true;
        vector<int> color(v, -1);

        int guards = 0;
        for (int i = 0; bipartite && i < v; i++)
            if (color[i] == -1){
                queue<int> q;
                q.push(i);
                color[i] = 0;
                int zero = 1, one = 0;

                while (bipartite && !q.empty()){
                    int u = q.front();
                    q.pop();
                    for (int dest: adjList[u]){
                        if (color[dest] == -1){
                            color[dest] = 1 - color[u];
                            q.push(dest);
                            if (color[dest] == 0)
                                zero++;
                            else
                                one++;
                        }
                        else if (color[dest] == color[u]){
                            bipartite = false;
                            break;
                        }
                    }
                }

                if (zero + one == 1)
                    guards++;
                else if (zero < one)
                    guards += zero;
                else
                    guards += one;
            }
        if (!bipartite)
            printf("-1\n");
        else
            printf("%d\n", guards);
    }
}
