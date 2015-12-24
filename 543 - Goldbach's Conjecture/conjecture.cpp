#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

#define MAX 1000500

bitset<MAX> bs;
vector<int> primes;

void sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for (long long i = 2; i < MAX; i++)
		if (bs[i]){
			for (long long j = i * i; j < MAX; j += i)
				bs[j] = 0;
			primes.push_back(static_cast<int>(i));
		}
}

int main(){
	sieve();
	int n;
	while (scanf("%d", &n) && n){
		bool printed = false;
		for (int i = 0; i < primes.size(); i++)
			if (primes[i] * 2 > n)
				break;
			else if (bs[n - primes[i]] == 1){
				printf("%d = %d + %d\n", n, primes[i], n - primes[i]);
				printed = true;
				break;
			}
		if (!printed)
			printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}
