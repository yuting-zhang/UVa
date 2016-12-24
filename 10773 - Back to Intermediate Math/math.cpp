#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cases = 0; cases < T; cases++) {
        double d, v, u;
        scanf("%lf %lf %lf", &d, &v, &u);
        printf("Case %d: ", cases + 1);
        if (abs(v) <= 1e-10 || u <= v)
            printf("can't determine\n");
        else {
            double theta = asin((double)v / u);
            printf("%.3f\n", d / (u * cos(theta)) - d / u);
        }
    }
    return 0; 
}
