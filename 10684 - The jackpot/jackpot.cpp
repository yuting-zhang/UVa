#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N;
    int sequence[10005];
    while (scanf("%d", &N) && N){
        for (int i = 0; i < N; i++)
            scanf("%d", &sequence[i]);
        int answer = -1;
        int sum = 0;
        for (int i = 0; i < N; i++){
            if (sum < 0)
                sum = 0;
            sum += sequence[i];
            if (sum > answer)
                answer = sum;
        }
        if (answer > 0)
            printf("The maximum winning streak is %d.\n", answer);
        else
            printf("Losing streak.\n");
    }
    return 0;
}
