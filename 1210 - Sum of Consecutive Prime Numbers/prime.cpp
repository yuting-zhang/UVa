#include <bits/stdc++.h>

using namespace std;

vector<int> get_primes() {
    vector<int> primes;
    vector<bool> sieve(10001, true);
    for (int i = 2; i <= 10000; i++) {
        if (sieve[i]) {
            primes.push_back(i);
            int j = i * 2;
            while (j < 10001) {
                sieve[j] = false;
                j += i;
            }
        }
    }
    return primes;
}

int main() {
    vector<int> primes = get_primes();
    int N;
    while (scanf("%d", &N) && N) {
        int answer = 0, sum = 0, head = 0;

        for (int tail = 0; tail < primes.size(); tail++) {
            sum += primes[tail];
            while (head <= tail && sum > N) {
                sum -= primes[head];
                head++;
            }
            if (head > tail)
                break;
            if (N == sum)
                answer++;
        }
        printf("%d\n", answer);
    }

    return 0;
}
