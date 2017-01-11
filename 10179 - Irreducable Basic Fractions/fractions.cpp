#include <bits/stdc++.h>

using namespace std;

#define UPPERBOUND 32000
vector<int> primes;

void sieve() {
    bitset<UPPERBOUND> bs;
    bs.set();
    bs[0] = bs[1] = false;

    for (long long i = 2; i < UPPERBOUND; i++)
        if (bs[i]) {
            for (long long j = i * i; j < UPPERBOUND; j += i)
                bs[j] = false;
            primes.push_back(static_cast<int>(i));
        }
}

long long Euler_totient(int N) {
    long long phi = N;

    int index = 0, factor = primes[index];

    while (factor * factor <= N) {
        if (N % factor == 0)
            phi -= phi / factor;
        while (N % factor == 0) 
            N /= factor;
        factor = primes[++index];
    }

    if (N != 1)
        phi -= phi / N;
    return phi;
}

int main(){
    sieve();

    int N;
    while (scanf("%d", &N) && N) {
        printf("%lld\n", Euler_totient(N));
    }
	return 0;
}
