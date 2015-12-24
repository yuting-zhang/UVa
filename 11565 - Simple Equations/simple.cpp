#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	while (N--){
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		int x, y, z;
		bool solved = false;
		for (int x = -100; x <= 22 && !solved; x++){
			if (x * x > C)
				continue;
			for (int y = x + 1; y <= 100 && !solved; y++){
				int z = A - x - y;
				if (z == x || z == y)
					continue;
				if (z < y)
					break;
				if (x * y * z == B && x * x +  y * y + z * z == C){
					printf("%d %d %d\n", x, y, z);
					solved = true;
				}
			}
		}
		if (!solved)
			printf("No solution.\n");
	}
	return 0;
}
