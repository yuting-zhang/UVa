#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265359

int main(){
    int a, b, c;
    while (scanf("%d %d %d", &a, &b, &c) == 3){
        double s = (double)(a + b + c) / 2;
        double triangle = sqrt(s * (s - a) * (s - b) * (s - c));
        double in_circle = PI * pow((triangle / s), 2);
        double out_circle = PI * pow((double)a * b *c / (4 * triangle), 2);
        out_circle -= triangle;
        triangle -= in_circle;
        printf("%.4f %.4f %.4f\n", out_circle, triangle, in_circle);
    }
    return 0;
}
