#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long gcd(long long a, long long b){
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

long long lcm(long long a, long long b){
	return a / gcd(a, b) * b;
}

int main(){
	int n, t;
	while (scanf("%d %d", &n, &t) && n && t){
		vector<long long> coins(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &coins[i]);
		vector<long long> tables(t);
		for (int i = 0; i < t; i++)
			scanf("%d", &tables[i]);
		vector<long long> below(t, 0), above(t, LLONG_MAX);

		vector<int> states(n, 0);
		states[n - 1] = states[n - 2] = states[n - 3] =states[n - 4] = 1;
		do{
			int index[4], count = 0;
			for (int i = 0; i < states.size(); i++)
				if (states[i] == 1)
					index[count++] = i;

			long long value = lcm(coins[index[0]], lcm(coins[index[1]], lcm(coins[index[2]], coins[index[3]])));

			for (int i = 0; i < t; i++){
				long long m = tables[i] / value;
				below[i] = max(below[i], m * value);
				if (below[i] == tables[i])
					above[i] = below[i];
				else
					above[i] = min(above[i], (m + 1) * value);
			}
		}while (next_permutation(states.begin(), states.end()));
		for (int i = 0; i < t; i++)
			printf("%lld %lld\n", below[i], above[i]);

	}
	return 0;
}

