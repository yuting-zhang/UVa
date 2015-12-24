#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int binary_search(const vector<long long>& sums, long long val, int lo, int hi){
	if (lo > hi)
		return lo;
	int mid = (lo + hi) / 2;
	if (sums[mid] == val)
		return mid;
	if (sums[mid] < val)
		return binary_search(sums, val, mid + 1, hi);
	return binary_search(sums, val, lo, mid - 1);
}

void  calc(long long& closest, long long val, int index, vector<long long>& sums){
	if (index < 0 || index >= sums.size())
		return;
	long long old_diff = abs(closest - val), new_diff = abs(sums[index] - val);
	if (new_diff < old_diff)
		closest = sums[index];
}

int main(){
	int n, tc = 0;
	while (scanf("%d", &n) == 1 && n){
		tc++;
		vector<long long> nums(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &nums[i]);
		vector<long long> sums;
		sums.reserve(n * n);
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				sums.push_back(nums[i] + nums[j]);
		sort(sums.begin(), sums.end());
		int m;
		scanf("%d", &m);
		printf("Case %d:\n", tc);
		while(m--){
			long long val;
			scanf("%lld", &val);
			int index = binary_search(sums, val, 0, sums.size() - 1);
			long long closest = sums[0];
			calc(closest, val, index, sums);
			calc(closest, val, index + 1, sums);
			calc(closest, val, index - 1, sums);
			printf("Closest sum to %lld is %lld.\n", val, closest);
		}	
	}	
	return 0;
}
