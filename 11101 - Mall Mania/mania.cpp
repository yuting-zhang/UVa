#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

#define MAX 2005

vector<vector<int>> dist;
int length;

const int walk[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main(){
    int p;
    while (scanf("%d", &p) && p){
        dist.assign(MAX, vector<int>(MAX, (1 << 30)));
        queue<pair<int, int>> q;
        for (int i = 0; i < p; i++){
            int a, s;
            scanf("%d %d", &a, &s);
            dist[a][s] = 0;
            q.push({a, s});
        }
        scanf("%d", &p);
        for (int i = 0; i < p; i++){
            int a, s;
            scanf("%d %d", &a, &s);
            dist[a][s] = -1;
        }

        length = (1 << 30);
        bool reach = false;

        while (!q.empty() && !reach){
            pair<int, int> front = q.front();
            q.pop();
            int a = front.first, s = front.second;
            for (int i = 0; i < 4; i++){
                int new_a = a + walk[i][0], new_s = s + walk[i][1];
                if (new_a >= 0 && new_a < MAX && new_s >= 0 && new_s < MAX){
                    if (dist[new_a][new_s] == -1){
                        length = dist[a][s] + 1;
                        reach = true;
                        break;
                    }
                    if (dist[new_a][new_s] == (1 << 30)){
                        dist[new_a][new_s] = dist[a][s] + 1;
                        q.push({new_a, new_s});
                    }
                }
            }
        }
        printf("%d\n", length);
    }
    return 0;
}

