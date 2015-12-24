#include <iostream>

using namespace std;

int main(){
    double H, U, D, F;
    while (scanf("%lf %lf %lf %lf", &H, &U, &D, &F) == 4 && H != 0){
        int day = 0;
        double height = 0;
        double fatigue = U * F / 100;
        while (height < H && height >=0){
            day++;
            height += U;
            if (height > H)
                break;
            U -= fatigue;
            if (U < 0)
                U = 0;
            height -= D;

        }
        if (height > H)
            printf("success on day %d\n", day);
        else
            printf("failure on day %d\n", day);
    }
    return 0;
}
