#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    while (N--){
        int D, L;
        scanf("%d %d", &D, &L);
        double b = sqrt(pow((double)L / 2, 2) - pow((double)D / 2, 2)),
               a = ((double)L - D) / 2 + (double)D / 2,
               area = 2 * acos(0) * a * b;
        printf("%.3f\n", area);
    }
}
