#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
vector<int> ladder;

bool simulate(int k){
	int height = 0;
	for (int i = 0; i < n; i++)
		if (ladder[i] - height > k)
			return false;
		else{
			if (ladder[i] - height == k)
				k--;
			height = ladder[i];
		}
	return true;
}
int main(){
	int T;
	scanf("%d", &T);
	for (int case_cnt = 0; case_cnt < T; case_cnt++){
		scanf("%d", &n);
		ladder.assign(n, 0);
		for (int i = 0; i < n; i++)
			scanf("%d", &ladder[i]);
		int lower = 1, upper = 11000000;
		int solution = upper;
		while (lower <= upper){
			int mid = (lower + upper) / 2;
			if (simulate(mid)){
				solution = mid;
				upper = mid - 1;
			}
			else
				lower = mid + 1;
		}
		printf("Case %d: %d\n", case_cnt + 1, solution);	
	}
}
