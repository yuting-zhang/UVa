#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <array>

using namespace std;

char grid1[5][6], grid2[5][6], grid[5][6];
int gridSize[5];
int solCounts[5];

int k, cnt;

char solution[5];


void backtrack(int pos){
	if (pos == 5)
		return;
	
	int index = 0;
	while (solCounts[pos] + cnt <= k){
		cnt += solCounts[pos];
		index++;
	}
	solution[pos] = grid[pos][index];
	backtrack(pos + 1);
}
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &k);
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 5; j++)
				scanf(" %c", &grid1[j][i]);

		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 5; j++)
				scanf(" %c", &grid2[j][i]);

		for (int i = 0; i < 5; i++){
			sort(begin(grid1[i]), end(grid1[i]));
			sort(begin(grid2[i]), end(grid2[i]));
		}

		memset(gridSize, 0, sizeof gridSize);
		for (int i = 0; i < 5; i++){
			char previous = ' ';
			for (int j = 0; j < 6; j++)
				for (int k = 0; k < 6; k++)
					if (grid1[i][j] == grid2[i][k] && grid1[i][j] != previous){
						grid[i][gridSize[i]++] = grid1[i][j];
						previous = grid1[i][j];
					}
		}	

		solCounts[4] = 1;
		for (int i = 3; i >= 0; i--)
			solCounts[i] = solCounts[i + 1] * gridSize[i + 1];

		cnt = 1;
		if (solCounts[0] * gridSize[0] < k)
			printf("NO\n");
		else{
			backtrack(0);
			for (int i = 0; i < 5; i++)
				printf("%c", solution[i]);
			printf("\n");
		}
	}
	return 0;
}
