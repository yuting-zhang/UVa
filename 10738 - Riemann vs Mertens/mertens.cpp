#include <bits/stdc++.h>

using namespace std;

#define UPPERBOUND 1000100

vector<int> sieve_kai() {
    vector<int> factors(UPPERBOUND);
    bitset<UPPERBOUND> square_free;
    square_free.set();

    for (long long i = 2; i < UPPERBOUND; i++)
        if (factors[i] == 0) {
            for (long long j = i; j < UPPERBOUND; j += i) {
                factors[j]++;
                if (j % (i * i) == 0)
                    square_free[j] = false;
            }
        }

    vector<int> mu(UPPERBOUND);
    mu[1] = 1;
    for (int i = 2; i < UPPERBOUND; i++)
        if (!square_free[i])
            mu[i] = 0;
        else 
            mu[i] = factors[i] % 2 == 0 ? 1 : -1;
    return mu; 
}

int main() {
    vector<int> mu = sieve_kai();
    vector<int> M(UPPERBOUND);
    for (int i = 1; i < UPPERBOUND; i++)
        M[i] = M[i - 1] + mu[i];

    int n;
    while (scanf("%d", &n) && n)
        printf("%8d%8d%8d\n", n, mu[n], M[n]);
    return 0;
}
