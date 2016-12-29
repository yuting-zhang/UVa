#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) && n)
        printf("%d\n", (int)(log(n) / log(2)));
    return 0;
}
