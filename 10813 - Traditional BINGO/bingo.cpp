#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	while (n--){
		int card[5][5];
		card[2][2] = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				if (i == 2 && j == 2)
					continue;
				else
					scanf("%d", &card[i][j]);
		
		int numbers[75];
		for (int i = 0; i < 75; i++)
			scanf("%d", &numbers[i]);

		int bingo[12]; // 0 - 4 row, 5 - 9 column, 10 -> diagonal, 11 <- diagonal
		memset(bingo, 0, sizeof(bingo));
		bingo[2] = bingo[7] = bingo[10] = bingo[11] = 1;

		int count = 0;
		bool found = false;
		for (count = 0; count < 75; count++){
			for (int i = 0; i < 5; i++){
				for (int j = 0; j < 5; j++)
					if (numbers[count] == card[i][j]){
						if (++bingo[i] >= 5){
							found = true;
							break;
						}
						if (++bingo[j + 5] >= 5){
							found = true;
							break;
						}
						if (i == j)
							if (++bingo[10] >= 5){
								found = true;
								break;
							}
						if (i + j == 4)
							if (++bingo[11] >= 5){
								found = true;
								break;
							}
					}
				if (found)
					break;
			}
			if (found)
				break;
		}
	
		printf("BINGO after %d numbers announced\n", ++count);
	}
	return 0;
}
