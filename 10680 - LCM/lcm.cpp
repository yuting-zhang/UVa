#include <bits/stdc++.h>

using namespace std;

#define BOUND 1050

vector<int> sieve() {
    bitset<BOUND> bs;
    bs.set();
    bs[0] = bs[1] = false;

    vector<int> primes;
    for (long long i = 2; i < BOUND; i++) 
        if (bs[i]) {
            for (long long j = i * i; j < BOUND; j += i)
                bs[j] = false;
            primes.push_back((int)i); 
        }
    return primes;
}

int main() {
    auto primes = sieve(); 
    vector<int> lcm(primes.size());
    vector<int> rest(1000001, 1);
    vector<int> two(1000001, 0), five(1000001, 0);

    unordered_map<int, bool> visited;

    for (int i = 2; i <= 1000000; i++) {
        rest[i] = rest[i - 1];
        two[i] = two[i - 1];
        five[i] = five[i - 1];

        int temp = i, index = 0, prime = primes[index];
        while (temp != 1) {
            int counter = 0;
            while (temp % prime == 0) {
                temp /= prime;
                counter++;
            }

            if (counter > lcm[index]) {
                if (index == 0)
                    two[i] = counter;
                else if (index == 2)
                    five[i] = counter;
                else 
                    for (int j = 0; j < counter - lcm[index]; j++)
                        rest[i] = (rest[i] * prime) % 10;
                lcm[index] = counter;
            }
            if (index == primes.size() - 1)
                break;
            prime = primes[++index];
        }
        
        if (temp != 1) {
            if (!visited[temp]) {
                visited[temp] = true;
                rest[i] = (rest[i] * temp) % 10;
            }
        }
    }

    int N;
    while (scanf("%d", &N) && N) {
        int product = rest[N];
        if (two[N] > five[N])
            for (int i = 0; i < two[N] - five[N]; i++)
                product = (product * 2) % 10;
        else
            for (int i = 0; i < five[N] - two[N]; i++)
                product = (product * 5) % 10;

        printf("%d\n", product);
    }
    return 0;
}
