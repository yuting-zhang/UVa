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

long long num_of_divisors(int N) {
    long long divisors = 1;

    int index = 0, factor = primes[index];

    while (factor * factor <= N) {
        int power = 0;
        while (N % factor == 0) {
            power++;
            N /= factor;
        }
        divisors *= power + 1;
        factor = primes[++index];
    }

    if (N != 1)
        divisors *= 2;
    return divisors;
}

int main(){
    sieve();

    int N;
    scanf("%d", &N);
    while (N--) {
        int L, U;
        scanf("%d %d", &L, &U);
        int P = -1;
        long long D = 0;
        for (int i = L; i <= U; i++) {
            long long divisors = num_of_divisors(i);
            if (divisors > D) {
                P = i;
                D = divisors;
            }
        }
        printf("Between %d and %d, %d has a maximum of %lld divisors.\n",
                L, U, P, D);
    }
	return 0;
}
