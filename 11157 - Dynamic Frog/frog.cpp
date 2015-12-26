#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for (int test_case = 0; test_case < T; test_case++){
        int N, D;
        scanf("%d %d", &N, &D);
        int stones[105];
        bool big[105];
        for (int i = 0; i < N; i++){
            char type;
            int dist;
            scanf(" %c-%d ", &type, &dist);
            stones[i] = dist;
            big[i] = (type == 'B');
        }
        stones[N] = D;
        big[N] = true;

        int jump = 0, position1 = 0, position2 = 0;
        bool firstTrip = true;
        for (int i = 0; i <= N; i++){
            if (big[i]){
                jump = max(jump, stones[i] - position1);
                jump = max(jump, stones[i] - position2);
                position1 = position2 = stones[i];
                firstTrip = true;
            }
            else{
                if (firstTrip){
                    jump = max(jump, stones[i] - position1);
                    position1 = stones[i];
                    firstTrip = false;
                }
                else{
                    jump = max(jump, stones[i] - position2);
                    position2 = stones[i];
                    firstTrip = true;
                }
            }
        }
        printf("Case %d: %d\n", test_case + 1, jump);
	}
	return 0;
}
