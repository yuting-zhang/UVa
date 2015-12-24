#include <iostream>
#include <cmath>

#define PI 3.14159265359

int main(){
    double l, w, h, theta;

    while (scanf("%lf %lf %lf %lf", &l, &w, &h, &theta) == 4){
        theta = theta * PI / 180;
        double critical = atan(h / l);
        if (theta < critical){
            printf("%.3f mL\n", l * h * w - 0.5 * l * tan(theta) * l * w);
        } else {
            printf("%.3f mL\n", 0.5 * h / tan(theta) * h * w);
        }
    }

    return 0;
}
