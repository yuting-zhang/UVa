#include <bits/stdc++.h>

using namespace std;

#define UPPERBOUND 1000050

vector<int> sieve_kai() {
    vector<int> factors(UPPERBOUND, 0);

    for (long long i = 2; i < UPPERBOUND; i++)
        if (factors[i] == 0) {
            for (long long j = i; j < UPPERBOUND; j += i)
                factors[j]++;
        }
    return factors;
}

int main() {
    vector<int> factors = sieve_kai();
    int n;
    while (scanf("%d", &n) && n)
        printf("%d : %d\n", n, factors[n]);
    return 0;
}
