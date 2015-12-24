#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int sum, diff;
		scanf("%d %d", &sum, &diff);
		if ((sum + diff) % 2){
			printf("impossible\n");
			continue;
		}
		int a = (sum + diff) / 2,
			b = sum - a;
		if (a < 0 || b < 0)
			printf("impossible\n");
		else
			printf("%d %d\n", a, b);
	}
	return 0;
}
