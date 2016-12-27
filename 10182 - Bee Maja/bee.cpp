#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<pair<int, int>> solution(100000);
    solution[0] = {0, 0};
    solution[1] = {0, 1};
    int x = 0, y = 1;
    int layer = 1, dir = 0, step = 0;
    
    int walk[6][2] = {{-1, 1}, {-1, 0}, {0, -1}, {1, -1}, {1, 0}, {0, 1}};
    int num = 2;
    while (num < 100000) {
        if (dir == 0 && step == layer - 1 || step == layer) {
            dir++;
            step = 0;
        }

        if (dir == 6) {
            x += walk[5][0];
            y += walk[5][1];
            solution[num++] = {x, y};

            dir = 0;
            step = 0;
            layer++;
        }

        x += walk[dir][0];
        y += walk[dir][1];
        solution[num++] = {x, y};
        step++;
    }

    int n;
    while (scanf("%d", &n) == 1)
        printf("%d %d\n", solution[n - 1].first, solution[n - 1].second);

    return 0;
}
