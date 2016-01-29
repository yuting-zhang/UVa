#include <cstdio>

using namespace std;

#define MAXTRIG 1000005
int main(){
    long long trig[MAXTRIG];
    trig[0] = trig[1] = trig[2] = trig[3] = 0;
    for (long long i = 4; i < MAXTRIG; i++)
        trig[i] = trig[i - 1] + (0 + i / 2 - 1) * (i / 2) - (i % 2 == 0 ? i / 2 - 1 : 0);
    int n;
    while (scanf("%d", &n) && n >= 3)
        printf("%lld\n", trig[n]);
    return 0;
}
