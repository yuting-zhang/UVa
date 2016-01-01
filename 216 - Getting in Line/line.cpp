#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

int n;
double adjMat[10][10];
int coords[10][2];
double memo[10][500];
int next[10][500];

double dp(int pos, int mask){
    if (mask == (1 << n) - 1)
        return 0;

    if (memo[pos][mask] >= -1)
        return memo[pos][mask];

    double& cell = memo[pos][mask];
    cell = INT_MAX / 2;
    for (int i = 0; i < n; i++)
        if (!((1 << i) & mask)){
            double result = adjMat[pos][i] + dp(i, mask | (1 << i));
            if (result < cell){
                cell = result;
                next[pos][mask] = i;
            }
        }
    return cell;
}

int main(){
    int test_case = 0;
    while (scanf("%d", &n) && n){
        test_case++;
        for (int i = 0; i < n; i++)
            scanf("%d %d", &coords[i][0], &coords[i][1]);
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (i == j)
                    adjMat[i][j] = 0;
                else
                    adjMat[i][j] = adjMat[j][i] = sqrt(pow(coords[i][0] - coords[j][0], 2)+
                                                       pow(coords[i][1] - coords[j][1], 2));
        memset(memo, -1, sizeof memo);
        memset(next, -1, sizeof next);

        double answer = INT_MAX / 2;
        int source = 0;
        for (int i = 0; i < n; i++){
            double result = dp(i, 1 << i);
            if (result < answer){
                answer = result;
                source = i;
            }
        }
         
        printf("**********************************************************\n");
        printf("Network #%d\n", test_case);
        
        int mask = (1 << source);
        while (next[source][mask] != -1){
            int next_comp = next[source][mask];
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", 
                   coords[source][0], coords[source][1], coords[next_comp][0], coords[next_comp][1], 
                   adjMat[source][next_comp] + 16);
            source = next_comp;
            mask |= (1 << source);
        }

        printf("Number of feet of cable required is %.2f.\n", answer + 16 * (n - 1));

        
    }
}
