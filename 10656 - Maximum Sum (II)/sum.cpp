#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int N;
	while (scanf("%d", &N) && N){
		bool firstValue = true;
		bool printed = false;
		for (int i = 0; i < N; i++){
			int val;
			scanf("%d", &val);
			if (val > 0){
				if (firstValue){
					firstValue = false;
					printf("%d", val);
				}
				else
					printf(" %d", val);
				printed = true;
			}
		}
		if (!printed)
			printf("0");
		printf("\n");
	}
	return 0;
}
