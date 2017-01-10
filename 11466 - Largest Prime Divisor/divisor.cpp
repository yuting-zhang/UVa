#include <bits/stdc++.h>

using namespace std;

#define BOUND 10000100

vector<int> sieve() {
    bitset<BOUND> bs;
    bs.set();
    bs[0] = bs[1] = false;

    vector<int> primes;
    for (long long i = 2; i < BOUND; i++) {
        if (bs[i]) {
            for (long long j = i * i; j < BOUND; j += i)
                bs[j] = false;
            primes.push_back(static_cast<int>(i));
        }
    }
    return primes;
}

int main() {
    long long num;
    vector<int> primes = sieve();

    while (scanf("%lld", &num) && num) {
        num = abs(num);
        long long index = 0, prime = primes[index], factors = 0, largest = -1;

        while (prime * prime <= num) {
            bool first = true;
            while (num % prime == 0) {
                num /= prime;
                largest = prime;
                if (first) {
                    factors++;
                    first = false;
                }
            }
            prime = primes[++index];
        }

        if (num != 1) {
            largest = num;
            factors++;
        }

        if (factors < 2)
            printf("-1\n");
        else
            printf("%lld\n", largest);
    }

    return 0;
}
