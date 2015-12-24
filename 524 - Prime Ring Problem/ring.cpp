#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n;
bool taken[20];
int ring[20];
bool primes[100];

void precalc(){
	memset(primes, false, sizeof primes);
	for (int i = 2; i <= 100; i++){
		bool isPrime = true;
		for (int j = 2; j <= sqrt(i); j++)
			if (i % j == 0){
				isPrime = false;
				break;
			}
		if (isPrime)
			primes[i] = true;
	}
}

void backtrack(int num){
	if (num == n){
		if (!primes[ring[0] + ring[n - 1]])
			return;
		for (int i = 0; i < n - 1; i++)
			printf("%d ", ring[i]);
		printf("%d\n", ring[n - 1]);
		return;
	}

	for (int i = 2; i <= n; i++){
		if (!taken[i] && primes[ring[num - 1] + i]){
			ring[num] = i;
			taken[i] = true;
			backtrack(num + 1);
			taken[i] = false;
		}
	}
}

int main(){
	precalc();
	int count = 0;
	while (scanf("%d", &n) == 1){
		count++;
		if (count != 1)
			printf("\n");
		printf("Case %d:\n", count);
		memset(taken, false, sizeof taken);
		memset(ring, 0, sizeof ring);
		taken[1] = true;
		ring[0] = 1;
		backtrack(1);
	}
	return 0;
}
