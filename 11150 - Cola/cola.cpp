#include <cstdio>

using namespace std;

int main(){
    int N;
    while (scanf("%d", &N) == 1){
        if (N % 2 == 0)
            printf("%d\n", N / 2 * 3);
        else
            printf("%d\n", N / 2 * 3 + 1);
    }
}
