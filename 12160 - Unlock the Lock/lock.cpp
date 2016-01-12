#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
    int L, U, R;
    int button[15];
    bool visited[10000];
    int dist[10000];
    int test_case = 0;
    while (scanf("%d %d %d", &L, &U, &R) && R){
        test_case++;
        printf("Case %d: ", test_case);
        for (int i = 0; i < R; i++)
            scanf("%d", &button[i]);
        memset(visited, 0, sizeof visited);
        memset(dist, 7, sizeof dist);
        
        dist[L] = 0;
        queue<int> q;
        visited[L] = true;
        q.push(L);
        bool found = (L == U);
        while (!q.empty() && !found){
            int code = q.front();
            q.pop();
            for (int i = 0; i < R; i++){
                int new_code = (code + button[i]) % 10000;
                if (!visited[new_code]){
                    visited[new_code] = true;
                    dist[new_code] = dist[code] + 1;
                    if (new_code == U){
                        found = true;
                        break;
                    }
                    q.push(new_code);
                }
            }
        }
        
        if (found)
            printf("%d\n", dist[U]);
        else
            printf("Permanently Locked\n");
    }
    return 0;
}
