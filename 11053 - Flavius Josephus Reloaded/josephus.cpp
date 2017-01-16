#include <bits/stdc++.h>

using namespace std;

long long a, b, N;

long long next(long long x) {
    return (a * x % N * x % N + b) % N;
}

int main(){
    while (scanf("%lld %lld %lld", &N, &a, &b) == 3) {
        long long slow = next(0), fast = next(next(0));

        while (slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }

        int lambda = 1;
        slow = next(slow);
        while (slow != fast) {
            slow = next(slow);
            lambda++;
        }
        printf("%d\n", (int)N - lambda);
    }
    return 0;
}
