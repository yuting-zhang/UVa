#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool victory(char a, char b){
	if (a == 'R' && b == 'S')
		return true;
	if (a == 'S' && b == 'P')
		return true;
	if (a == 'P' && b == 'R')
		return true;
	return false;
}

int main(){
	int t;
	scanf("%d", &t);
	for (int case_no = 0; case_no < t; case_no++){
		if (case_no)
			printf("\n");
		int r, c, n;
		scanf("%d %d %d", &r, &c, &n);

		vector<vector<char>> grid(r, vector<char>(c));
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				scanf(" %c", &grid[i][j]);

		vector<vector<char>> prev = grid;

		for (int i = 0; i < n; i++){
			for (int j = 0; j < r; j++)
				for (int k = 0; k < c; k++){
					if (k < c - 1 && prev[j][k] != prev[j][k + 1]){
					   if (victory(prev[j][k], prev[j][k + 1]))
							grid[j][k + 1] = prev[j][k];
					   else
						   grid[j][k] = prev[j][k + 1];
					}
					if (j < r - 1 && prev[j][k] != prev[j + 1][k]){
						if (victory(prev[j][k], prev[j + 1][k]))
							grid[j + 1][k] = prev[j][k];
						else
							grid[j][k] = prev[j + 1][k];
					}
				}
			prev = grid;
		}

		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++)
				printf("%c", grid[i][j]);
			printf("\n");
		}
	}
	return 0;
}
