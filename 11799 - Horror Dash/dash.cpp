#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i){
        int N;
        scanf("%d", &N);
        int max_speed = 0;
        for (int j = 0; j < N; ++j){
            int speed;
            scanf("%d", &speed);
            max_speed = max(max_speed, speed);
        }
        printf("Case %d: %d\n", i + 1, max_speed);
    }
    return 0;
}
