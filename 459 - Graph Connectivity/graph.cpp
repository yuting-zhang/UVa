#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;

void DFS(int node){
    visited[node] = true;
    for (int dest: adjList[node])
        if (!visited[dest])
            DFS(dest);
}

int main(){
    int T;
    bool first_case = true;
    scanf("%d\n\n", &T);
    while (T--){
        if (first_case)
            first_case = false;
        else
            printf("\n");
        
        adjList.clear();

        string line;
        int N;
        getline(cin, line);
        N = line[0] - 'A' + 1;
        scanf("\n");

        adjList.assign(N, vector<int>());
        visited.assign(N, false);
        while (getline(cin, line) && !line.empty()){
            if (line.size() == 1){
                printf("%d\n", N);
                N = line[0] - 'A' + 1;
                scanf("\n");
                T--;

                adjList.assign(N, vector<int>());
                visited.assign(N, false);
                if (first_case)
                    first_case = false;
                else
                    printf("\n");
                continue;
            }
            adjList[line[0] - 'A'].push_back(line[1] - 'A');
            adjList[line[1] - 'A'].push_back(line[0] - 'A');
        }

        int cc_count = 0;
        for (int i = 0; i < N; i++)
            if (!visited[i]){
                cc_count++;
                DFS(i);
            }

        printf("%d\n", cc_count);
    }
    return 0;
}
