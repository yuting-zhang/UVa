#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int n;
	while(scanf("%d", &n) == 1){
		vector<bool> diff(n - 1, false);
		int old;
		scanf("%d", &old);
		int num;
		bool ok = true;
		for (int i = 0; i < n - 1; i++){
			scanf("%d", &num);
			int n_diff = abs(num - old);
			if (n_diff >= n || diff[n_diff])
				ok = false;
			if (n_diff < n)
				diff[n_diff] = true;
			old = num;
		}
		if (ok)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
		n = 0;
	}
	return 0;
}
