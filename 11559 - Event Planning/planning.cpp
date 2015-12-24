#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, B, H, W;
    while (scanf("%d %d %d %d", &N, &B, &H, &W) == 4){
        int min_cost = 2 * B;
        while (H--){
            int price;
            scanf("%d", &price);
            for (int i = 0; i < W; ++i){
                int bed;
                scanf("%d", &bed);
                if (bed >= N)
                    min_cost = min(min_cost, N * price);
            }
        }
        if (min_cost <= B)
            printf("%d\n", min_cost);
        else
            printf("stay home\n");
    }
    return 0;
}
