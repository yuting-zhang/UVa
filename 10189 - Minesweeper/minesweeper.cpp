#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	int n, m, case_no = 0;
	while (scanf("%d %d", &n, &m) && n){
		case_no++;
		if (case_no != 1)
			printf("\n");
		vector<vector<int>> field(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++){
				char ch;
				scanf(" %c", &ch);
				if (ch == '*')
					field[i][j] = -1;
				else
					field[i][j] = 0;
			}
		int direction[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
							   {0, -1}, {0, 1},
							   {1, -1}, {1, 0}, {1, 1}};

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (field[i][j] != -1)
					for (int k = 0; k < 8; k++){
						int new_y = i + direction[k][0],
							new_x = j + direction[k][1];
						if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n)
							if (field[new_y][new_x] == -1)
								field[i][j]++; 
					}   
		printf("Field #%d:\n", case_no);
		for (int i = 0; i < n; i++){
		   	for (int j = 0; j < m; j++)
				if (field[i][j] == -1)
					printf("*");
				else
					printf("%d", field[i][j]);
			printf("\n");
		}
	}	
	return 0;	
}
