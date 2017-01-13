#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) == 2) {
        int two = 0, five = 0, answer = 1;
        while (M--) {
            int temp = N;
            while (N % 2 == 0) {
                N /= 2;
                two++;
            }
            while (N % 5 == 0) {
                N /= 5;
                five++;
            }
            answer = N % 10 * answer % 10;
            N = temp - 1;
        }
        if (two > five) {
            two -= five;
            five = 0;
        }
        else {
            five -= two;
            two = 0;
        }
        while (two--)
            answer = answer * 2 % 10;
        while (five--)
            answer = answer * 5 % 10;
        printf("%d\n", answer);
    }
    return 0;
}
