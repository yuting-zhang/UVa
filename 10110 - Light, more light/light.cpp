#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    while (scanf("%lld", &n) && n) {
        if (pow((int)sqrt(n), 2) == n)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
