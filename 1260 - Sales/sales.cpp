#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int n;
		scanf("%d", &n);
		vector<int> sales(n);
		int sum = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &sales[i]);
			for (int j = 0; j < i; j++)
				if (sales[j] <= sales[i])
					sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}
