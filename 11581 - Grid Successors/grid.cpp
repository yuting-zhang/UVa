#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void f(int grid[3][3]){
	int n_grid[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++){
			int sum = 0;
			if (i != 0 )
				sum += grid[i - 1][j];
			if (i != 2)
				sum += grid[i + 1][j];
			if (j != 0)
				sum += grid[i][j - 1];
			if (j != 2)
				sum += grid[i][j + 1];
			n_grid[i][j] = sum % 2;
		}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			grid[i][j] = n_grid[i][j];
}

int main(){
	int n;
	scanf(" %d \n", &n);
	while (n--){
		scanf(" \n ");
		int grid[3][3];
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				char ch;
				scanf(" %c ", &ch);
				if (ch == '0')
					grid[i][j] = 0;
				else
					grid[i][j] = 1;
			}
			scanf(" \n ");
		}
		
		int count = 0;
		while (true){
			bool zeros = true;
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++)
					if (grid[i][j] != 0){
						zeros = false;
						break;
					}
				if (!zeros)
					break;
			}

			if (zeros)
				break;
			f(grid);
			count++;
		}
		printf("%d\n", count - 1);
	}
	return 0;
}
