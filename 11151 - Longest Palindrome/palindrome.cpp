#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    getchar();
    int length = 0;
    int memo[1005][1005];
    string buffer;
    while (T--){
        getline(cin, buffer);
        length = buffer.size();
        memset(memo, 0, sizeof(memo));
        
        for (int i = 0; i < length; i++)
            memo[1][i] = 1;

        for (int i = 2; i <= length; i++)
            for (int j = 0; j < length - i + 1; j++){
                if (buffer[j] == buffer[j + i - 1])
                    memo[i][j] = memo[i - 2][j + 1] + 2;
                else
                    memo[i][j] = max(memo[i - 1][j], memo[i - 1][j + 1]);
            }
        printf("%d\n", memo[length][0]); 
    }
}
