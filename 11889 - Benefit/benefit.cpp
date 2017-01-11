#include <bits/stdc++.h>

using namespace std;

#define BOUND 3200

vector<int> sieve() {
    bitset<BOUND> bs;
    bs.set();
    bs[0] = bs[1] = true;
    vector<int> primes;

    for (int i = 2; i < BOUND; i++) 
        if (bs[i]) {
            for (int j = i * i; j < BOUND; j += i) 
                bs[j] = false;
            primes.push_back(i);
        }
    return primes;
}

map<int, int> factor(int N, const vector<int> &primes) {
    int index = 0, prime = primes[index];
    map<int, int> factors;
    while (prime * prime <= N) {
        while (N % prime == 0) {
            N /= prime;
            factors[prime]++;
        }
        prime = primes[++index];
    }
    if (N != 1)
        factors[N]++;

    return factors;
}

int main(){
    int T;
    scanf("%d", &T);
    auto primes = sieve();

    while (T--) {
        int A, C;
        scanf("%d %d", &A, &C);
        map<int, int> A_factors = factor(A, primes);
        map<int, int> C_factors = factor(C, primes);
        int B = 1;

        for (auto it = C_factors.begin(); it != C_factors.end(); it++) {
            if (A_factors[it->first] < it->second) {
                for (int i = 0; i < it->second; i++)
                    B *= it->first;
                A_factors[it->first] = 0;
            }
            else if (A_factors[it->first] == it->second)
                A_factors[it->first] = 0; 
            else {
                B = -1;
                break;
            }
        }

        for (auto it = A_factors.begin(); it != A_factors.end(); it++)
            if (it->second != 0) {
                B = -1;
                break;
            }
            
        if (B == -1)
            printf("NO SOLUTION\n");
        else
            printf("%d\n", B);
    }

	return 0;
}
