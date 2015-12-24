#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

unsigned long long pow(int base, int power){
	unsigned long long ans = 1;
	while (power--)
		ans *= base;
	return ans;
}

int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--){
		int degree;
		scanf("%d", &degree);
		vector<int> coeffs(degree + 1);
		for (int i = 0; i <= degree; i++)
			scanf("%d", &coeffs[i]);
		int d, k;
		scanf("%d %d", &d, &k);
		int n = 1;
		while (n * d < k){
			k -= n * d;
			n++;
		}
		unsigned long long value = 0;
		for (int i = 0; i <= degree; i++)
			value += coeffs[i] * pow(n, i);
		printf("%lld\n", value);
	}	
	return 0;
}
