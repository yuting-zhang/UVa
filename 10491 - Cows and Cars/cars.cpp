#include <bits/stdc++.h>

using namespace std;

int main(){
    int ncows, ncars, nshow;
    while (scanf("%d %d %d", &ncows, &ncars, &nshow) == 3) {
        double case1 = 1.0 * ncars / (ncows + ncars) *
                        (ncars - 1) / (ncows + ncars - nshow - 1);
        double case2 = 1.0 * ncows / (ncows + ncars) *
                        ncars / (ncows + ncars - nshow - 1);
        printf("%.5f\n", case1 + case2);
    }
    return 0;
}
