#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int main(){
	int row, column;
	while (scanf("%d %d", &row, &column) && row && column){
		row += 2;
		column += 2;
		vector<vector<int>> maze(row, vector<int>(column, 0));

		for (int i = 0; i < row; i++){
			maze[i][0] = -1;
			maze[i][column - 1] = -1;
		}
		for (int i = 0; i < column; i++){
			maze[0][i] = -1;
			maze[row - 1][i] = -1;
		}

		int zero_count = 0;
		for (int i = 0; i < row - 2; i++)
			for (int j = 0; j < column - 2; j++){
				char temp;
				scanf(" %c ", &temp);
				if (temp == '1')
					maze[i + 1][j + 1] = -1;
				else
					zero_count++;
			}

		int x = 1, y = row - 2, face = 1; // 0 north, 1 east, 2 south, 3 west
		bool initial = true;
		int result[5];
		memset(result, 0, sizeof(result));
		result[0] = zero_count;
		
		int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
		while (true){
			if (x == 1 && y == row - 2){
				if (!initial)
					break;
				else
					initial = false;
			}
			
			if (maze[y][x] >= 0 && maze[y][x] < 5)
				result[maze[y][x]]--;
			maze[y][x]++;
			
			if (maze[y][x] >= 0 && maze[y][x] < 5)
				result[maze[y][x]]++;
			
			int next_face = (face + 1) % 4;
			while (maze[direction[next_face][0] + y][direction[next_face][1] + x] == -1)
				next_face = (next_face + 4 - 1 ) % 4;
			

			y += direction[next_face][0];
			x += direction[next_face][1];
			face = next_face;
		}
		printf("%3d%3d%3d%3d%3d\n", result[0], result[1], result[2], result[3], result[4]);
	}
	return 0;
}
