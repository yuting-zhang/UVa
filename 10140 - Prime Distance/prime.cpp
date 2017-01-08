#include <bits/stdc++.h>

using namespace std;

#define BOUND 1000000

bitset<BOUND> bs;
vector<long long> primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i <= BOUND; i++) {
        if (bs[i]) {
            for (long long j = i * i; j <= BOUND; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
    }
}

bool is_prime(long long N) {
    if (N <= BOUND)
        return bs[N];
    for (long long prime: primes) {
        if (prime > sqrt(N))
            return true;
        if (N % prime == 0)
            return false;
    }
    return true;
}

int main() {
    sieve();
    int L, U;
    while (scanf("%d %d", &L, &U) == 2) {
        pair<long long, long long> close, distant;
        long long close_dist = -1, distant_dist = -1;
        long long prev_prime = -1;
        for (long long i = L; i <= U; i++) 
            if (is_prime(i)) {
                if (prev_prime != -1) {
                    if (close_dist == -1 || i - prev_prime < close_dist) {
                        close = {prev_prime, i};
                        close_dist = i - prev_prime;
                    }
                    if (distant_dist == -1 || i - prev_prime > distant_dist) {
                        distant = {prev_prime, i};
                        distant_dist = i - prev_prime;
                    }
                }
                prev_prime = i;
            }
        if (close_dist != -1) 
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",
                close.first, close.second, distant.first, distant.second);
        else
            printf("There are no adjacent primes.\n");
    }
    return 0;
}
