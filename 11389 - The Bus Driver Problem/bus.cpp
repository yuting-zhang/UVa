#include <iostream>
#include <cstdio>
#include <array>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

int morning[105], evening[105];

int main(){
	int n, d, r;
	while (scanf("%d %d %d", &n, &d, &r) && n){
		for (int i = 0; i < n; i++)
			scanf("%d", &morning[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &evening[i]);
		sort(morning, morning + n);
		sort(evening, evening + n, greater<int>());
		int sum = 0;
		for (int i = 0; i < n; i++){
			int overtime = morning[i] + evening[i] - d;
			if (overtime > 0)
				sum += overtime * r;
		}
		printf("%d\n", sum);
	}
}
