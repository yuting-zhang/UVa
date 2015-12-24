#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int N;
	bool first = true;
	while (scanf("%d", &N) && N){
		if (first)
			first = false;
		else
			printf("\n");
		bool printed = false;
	
		for (int i = 1234; i <= 98765 / N; i++){

			int a = i, b = N * a, digits = (a < 10000 ? 1 : 0);
			while (a > 0){
				digits |= (1 << a % 10);
				a /= 10;
			}
			while (b > 0){
				digits |= (1 << b % 10);
				b /= 10;
			}
			if (digits == (1 << 10) - 1){
				printf("%0.5d / %0.5d = %d\n", i * N, i, N);
				printed = true;
			}
		}
		if (!printed)
			printf("There are no solutions for %d.\n", N);
	}
	return 0;
}
