#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<vector<int>>> parent;

void print_solution(int step, int source, int currency){
    if (step != 0)
        print_solution(step - 1, source, parent[step][source][currency]);
    printf("%d ", currency + 1);
}

int main(){
    int n;
    while (scanf("%d", &n) == 1){
        vector<vector<double>> adjMat(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++)
            adjMat[i][i] = 1.0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++)
                scanf("%lf", &adjMat[i][j]);
            for (int j = i + 1; j < n; j++)
                scanf("%lf", &adjMat[i][j]);
        }

        vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n, vector<double>(n, 0)));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[1][i][j] = adjMat[i][j];

        bool found = false;
        int source = -1;
        double rate = -1;
        parent.assign(n + 1, vector<vector<int>>(n, vector<int>(n, -1)));
        for (int k = 0; k <= n; k++)
            for (int i = 0; i < n; i++)
               for (int j = 0; j < n; j++)
                    parent[k][i][j] = i;

        int step;
        for (step = 2; step <= n; step++){
            for (int k = 0; k < n; k++)
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++){
                        if (dp[step - 1][i][k] * dp[1][k][j] > dp[step][i][j]){
                            dp[step][i][j] = dp[step - 1][i][k] * dp[1][k][j];
                            parent[step][i][j] = k;
                        }

                    }
            for (int i = 0; i < n; i++)
                if (dp[step][i][i] > 1.01){
                    found = true;
                    source = i;
                    rate = dp[step][i][i];
                    break;
                }
            if (found)
                break;
        }

        if (!found)
            printf("no arbitrage sequence exists\n");
        else{
            print_solution(step - 1, source, parent[step][source][source]);
            printf("%d\n", source + 1);
        }
    }
}
