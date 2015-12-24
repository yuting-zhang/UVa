#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

int main(){
	vector<long long> male, female;
	male.push_back(0);
	female.push_back(1);
	while (male.back() < INT_MAX && female.back() < INT_MAX){
		male.push_back(male.back() + female.back());
		female.push_back(male[male.size() - 2] + 1);
	}
	int N;
	while (scanf("%d", &N) && N != -1)
		printf("%lld %lld\n", male[N], male[N] + female[N]);
	return 0;
}
