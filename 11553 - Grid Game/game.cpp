#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		int grid[8][8];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &grid[i][j]);
		int order[8];
		for (int i = 0; i < n; i++)
			order[i] = i;
		int answer = INT_MAX;
		do{
			int score = 0;
			for (int i = 0; i < n; i++)
				score += grid[i][order[i]];
			if (score < answer)
				answer = score;
		}while (next_permutation(order, order + n));
		printf("%d\n", answer);
	}
	return 0;
}
