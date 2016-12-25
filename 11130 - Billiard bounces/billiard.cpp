#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1)

int main() {
    double a, b, v, A, s;
    while (scanf("%lf %lf %lf %lf %lf", &a, &b, &v, &A, &s) && a > 0) {
        double x = a / 2, y = b / 2;
        double vx = v * cos(A * PI / 180), vy = v * sin(A * PI / 180);
        double ax = -v / s * cos(A * PI / 180), ay = -v / s * sin(A * PI / 180);

        int vw = 0, hw = 0;

        double dx = vx * s + 0.5 * ax * s * s;
        double dy = vy * s + 0.5 * ay * s * s;

        vw = (dx + a / 2) / a;
        hw = (dy + b / 2) / b;

        printf("%d %d\n", vw, hw);
    }
    return 0;
}
