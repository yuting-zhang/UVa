#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int S, B;
	while(scanf("%d %d", &S, &B) && S){
		vector<int> left(S), right(S);
		for (int i = 0; i < S; i++){
			left[i] = i - 1;
			right[i] = i + 1;
		}
		right[S - 1] = -1;
		
		while(B--){
			int L, R;
			scanf("%d %d", &L, &R);
			L--, R--;
			if (left[L] != -1)
				right[left[L]] = right[R];
			if (right[R] != -1)
				left[right[R]] = left[L];

			if (left[L] == -1)
				printf("*");
			else
				printf("%d", left[L] + 1);

			printf(" ");
			if (right[R] == -1)
				printf("*");
			else
				printf("%d", right[R] + 1);
			printf("\n");
		}
		printf("-\n");
	}
	return 0;
}
