#include <cstdio>
#include <cstring>

using namespace std;

int N;

int visited[50010];
int forward[50010];
int size[50010];
int depths[50010];

int DFS(int node, int depth){
    if (visited[node] == 2)
        return size[node];

    if (visited[node] == 1){
        size[node] = depth - depths[node];
        return -size[node];
    }

    visited[node] = 1;
    depths[node] = depth;
    size[node] = 0;
    
    int result = DFS(forward[node], depth + 1);

    visited[node] = 2;
    if (result < 0){
        if (size[node] != 0)
            return size[node];
       size[node] = -result;
       return result;
    }
    size[node] = result + 1;

    return size[node];
}

int main(){
    int T;
    scanf("%d", &T);
    for (int test_case = 0; test_case < T; test_case++){
        scanf("%d", &N);
        for (int i = 0; i < N; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            forward[u - 1] = v - 1;
        }
        memset(visited, 0, sizeof visited);
        int answer = 0;
        for (int i = 0; i < N; i++){
            int result = DFS(i, 1);
            if (result > size[answer])
                answer = i;
        }

        printf("Case %d: %d\n", test_case + 1, answer + 1);
    }
    return 0;
}
