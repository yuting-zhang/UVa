#include <bits/stdc++.h>

using namespace std;

#define UPPERBOUND 1050

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

long long sum_of_divisors(int N) {
    int index = 0, factor = primes[index];
    long long sum = 1;
    while (factor * factor <= N) {
        int power = 0;
        while (N % factor == 0) {
            N /= factor;
            power++;
        }
        sum *= (pow(factor, power + 1) - 1) / (factor - 1);
        factor = primes[++index];
    }
    if (N != 1)
        sum *= (pow(N, 2) - 1) / (N - 1);
    return sum;
}

int main(){
    sieve();
    vector<int> solution(1001, -1);
    for (int num = 1; num <= 1000; num++) {
        long long sum = sum_of_divisors(num);
        if (sum <= 1000)
            solution[sum] = num;
    }

    int S, cases = 0;
    while (scanf("%d", &S) && S)
        printf("Case %d: %d\n", ++cases, solution[S]);
	return 0;
}
