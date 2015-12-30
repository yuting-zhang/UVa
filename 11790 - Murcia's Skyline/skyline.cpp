#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for (int test_case = 0; test_case < T; test_case++){
        int N;
        scanf("%d", &N);
        vector<int> height(N), width(N);

        for (int i = 0; i < N; i++)
            scanf("%d", &height[i]);
        for (int i = 0; i < N; i++)
            scanf("%d", &width[i]);


        vector<int> LIS(N), LDS(N);
        
        int inc = 0, dec = 0;
        for (int i = 0; i < N; i++){
            LIS[i] = LDS[i] = width[i];
            for (int j = 0; j < i; j++){
                if (height[j] < height[i] && LIS[j] + width[i] > LIS[i])
                    LIS[i] = LIS[j] + width[i];
                if (height[j] > height[i] && LDS[j] + width[i] > LDS[i])
                    LDS[i] = LDS[j] + width[i];
            }
            if (LDS[i] > dec)
                dec = LDS[i];
            if (LIS[i] > inc)
                inc = LIS[i];
        }
        if (inc >= dec)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", test_case + 1, inc, dec);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", test_case + 1, dec, inc);
    }
    return 0;
}
