#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cases = 0; cases < T; cases++) {
        int N;
        scanf("%d", &N);
        int captain = 0;
        for (int i = 0; i < N; i++) {
            int age;
            scanf("%d", &age);
            if (i == N / 2)
                captain = age;
        }
        printf("Case %d: %d\n", cases + 1, captain); 
    }
    return 0;
}
