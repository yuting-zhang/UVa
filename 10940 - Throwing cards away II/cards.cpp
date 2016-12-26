#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> solution(500000);
    solution[0] = 1;
    int exponent = 0;
    int number = 2;
    for (int i = 1; i < 500000; i++) {
        if (number > (1 << exponent)) {
            exponent++;
            number = 2;
        }
        solution[i] = number;
        number += 2;
    }

    while (scanf("%d", &n) && n)
        printf("%d\n", solution[n - 1]);

    return 0;
}
