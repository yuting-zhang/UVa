#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
	long long N, S;
	while (scanf("%lld %lld", &N, &S) == 2){
		vector<long long> nums(N);
		long long len = 0, sum = 0, min = N + 1, head = 0;
		for (int i = 0; i < N; i++){
			scanf("%lld", &nums[i]);
			sum += nums[i];
			len++;
			while (sum - nums[head] >= S){
				len--;
				sum -= nums[head];
				head++;
			}
			if (sum >= S && len < min)
				min = len;
		}
		if (S == 0 || min == N + 1)
			printf("0\n");
		else
			printf("%lld\n", min);
	}
	return 0;
}
