#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int gcd(int a, int b){
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b){
	return a * b / gcd(a, b);
}

int main(){
	int k;
	while (scanf("%d", &k) == 1){
		int a = 0;
		vector<pair<int, int>> result;
		while (true){
			a++;
			int m = lcm(a, k);
			int d1 = m / k, d2 = m / a;
			int d3 = d1 - d2;
			if (d3 <= 0)
				continue;
			if (d3 > d2)
				break;
			int divisor = gcd(d3, m);
			int b = m / divisor;
			if (b < a)
				break;
			if (divisor == d3 && b * divisor == m)
				result.push_back({b, a});
		}
		printf("%d\n", result.size());
		for (const auto& it: result)
			printf("1/%d = 1/%d + 1/%d\n", k, it.first, it.second);
	}
	return 0;
}
