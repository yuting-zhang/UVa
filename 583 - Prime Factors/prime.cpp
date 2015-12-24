#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

bitset<10000000> bs;
vector<int> primes;

void sieve(long long upperbound){
	long long sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (long long i = 2; i<= sieve_size; i++)
		if (bs[i]){
			for (long long j = i * i; j <= sieve_size; j += i)
				bs[j] = 0;
			primes.push_back(static_cast<int>(i));
		}
}

int main(){
	primes.reserve(50000);
	long long n;
	sieve(50000);
	while (scanf("%lld", &n) && n){
		vector<int> factors;
		printf("%lld = ", n);
		if (n < 0){
			printf("-1 x ");
			n = -n;
		}
		long long PF_index = 0, PF = primes[PF_index];
		while (n != 1 && PF * PF <= n){
			while (n % PF == 0){
				n /= PF;
				factors.push_back(PF);
			}
			PF = primes[++PF_index];
		}
		if (n != 1)
			factors.push_back(n);
		for (int i = 0; i < factors.size(); i++){
			if (i != 0)
				printf(" x ");
			printf("%d", factors[i]);
		}
		printf("\n");
	}
	return 0;
}
