#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;

vector<int> primes;

void sieve(int upperbound){
	bitset<1000> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= upperbound; i++) if (bs[i]){
		for (int j = i * i; j <= upperbound; j += i)
			bs[j] = 0;
		primes.push_back(i);
	}
}

vector<int> primeFactors(int N){
	vector<int> factors(150, 0);
	int PF_index = 0, PF = primes[PF_index];
	while (N != 1 && (PF * PF <= N)){
		while (N % PF == 0){
			N /= PF; 
			factors[PF]++;
		}
		PF = primes[++PF_index];
	}
	if (N != 1)
		factors[N]++;
	return factors;
}

int main(){
	sieve(150); 
	vector<vector<int>> factors;
	factors.push_back({1});
	factors.push_back({1});
	for (int i = 2; i <= 150; i++)
		factors.push_back(primeFactors(i));
	int N, M;

	while (scanf("%d %d", &N, &M) && N && M){
		vector<int> count(150, 0);
		for (int i = 2; i <= N; i++)
			for (int j = 2; j <= N; j++)
				count[j] += factors[i][j];
		for (int i = 2; i <= N - M; i++)
			for (int j = 2; j <= N - M; j++)
				count[j] -= factors[i][j];
		for (int i = 2; i <= M; i++)
			for (int j = 2; j <= M; j++)
				count[j] -= factors[i][j];
		ll answer = 1;
		for (int i = 2; i < 150; i++)
			for (int j = 1; j <= count[i]; j++)
				answer *= i;
		printf("%d things taken %d at a time is %lld exactly.\n", N, M, answer);
	}
	
}
