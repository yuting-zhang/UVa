#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int cars[2100];
int LIS[2100],
    LDS[2100];

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &cars[i]);
        reverse(cars, cars + n);
        int answer = 0;
        for (int i = 0; i < n; i++){
            LIS[i] = LDS[i] = 1;
            for (int j = 0; j < i; j++){
                if (cars[j] < cars[i] && LIS[j] + 1 > LIS[i])
                    LIS[i] = LIS[j] + 1;
                if (cars[j] > cars[i] && LDS[j] + 1 > LDS[i])
                    LDS[i] = LDS[j] + 1;
            }
            if (LIS[i] + LDS[i] - 1 > answer)
                answer = LIS[i] + LDS[i] - 1;
        }

        printf("%d\n", answer);
    }
    return 0;
}

