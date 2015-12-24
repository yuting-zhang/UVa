#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int L, C, R1, R2;
    while (scanf("%d %d %d %d", &L, &C, &R1, &R2) == 4 && L){
        if (min(L, C) >= max(R1 * 2, R2 * 2) && (pow(R1 - (L - R2), 2) + pow(R1 - (C - R2), 2) >= pow(R1 + R2, 2)))
            printf("S\n");
        else
            printf("N\n");
    }
    return 0;
}
