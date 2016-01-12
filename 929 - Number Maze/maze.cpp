#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

typedef pair<int, int> ii;

const int walk[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        int N, M;
        scanf("%d %d", &N, &M);
        vector<vector<int>> maze(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%d", &maze[i][j]);

        vector<vector<int>> dist(N, vector<int>(M, (1 << 30)));
        dist[0][0] = maze[0][0];
        priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
        pq.push({maze[0][0], {0, 0}});
        bool found = false;
        while (!pq.empty() && !found){
            auto front = pq.top();
            pq.pop();
            int cost = front.first, row = front.second.first, col = front.second.second;
            if (cost > dist[row][col])
                continue;
            for (int i = 0; i < 4; i++){
                int new_row = row + walk[i][0], new_col = col + walk[i][1];
                if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < M){
                    if (cost + maze[new_row][new_col] < dist[new_row][new_col]){
                        dist[new_row][new_col] = cost + maze[new_row][new_col];
                        pq.push({dist[new_row][new_col], {new_row, new_col}});
                        if (new_row == N - 1 && new_col == M - 1)
                            found = true;
                    }
                }
            }
        }
        printf("%d\n", dist[N - 1][M - 1]);
    }
    return 0;
}
