#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n;
	while (scanf("%d", &n) && n){
		int sum, num;
		scanf("%d", &num);
		sum = num;
		for (int i = 1; i < n; i++){
			scanf("%d", &num);
			sum ^= num;
		}
		if (sum != 0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
