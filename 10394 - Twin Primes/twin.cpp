#include <bits/stdc++.h>

using namespace std;

#define BOUND 20000000

bitset<BOUND> bs;
vector<long long> primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i <= BOUND; i++)
        if (bs[i]) {
            for (long long j = i * i; j <= BOUND; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
}

int main() {
    sieve();
    vector<pair<long long, long long>> twin;
    twin.reserve(100000);

    for (int i = 0; i < primes.size() - 1; i++) {
        if (primes[i + 1] - primes[i] == 2) {
            twin.push_back({primes[i], primes[i + 1]});
            if (twin.size() >= 100000)
                break;
        }
    }

    int S;
    while (scanf("%d", &S) == 1)
        printf("(%lld, %lld)\n", twin[S - 1].first, twin[S - 1].second);

    return 0;
}
