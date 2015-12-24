#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

typedef unsigned long long ull;

int main(){
	int N;
	while (scanf("%llu", &N) && N){
		priority_queue<ull, vector<ull>, greater<ull>> list;
		while (N--){
			ull num;
			scanf("%llu", &num);
			list.push(num);
		}
		ull cost = 0;
		while (true){
			ull sum = 0;
			sum += list.top();
			list.pop();
			sum += list.top();
			list.pop();
			cost += sum;
			if (list.empty())
				break;
			else
				list.push(sum);
		}
		printf("%llu\n", cost);
	}
	return 0;
}
