#include <iostream>
#include <cstdio>
#include <cstring>

const bool digit[10][7] = {{1, 1, 1, 1, 1, 1, 0},
						    {0, 1, 1, 0, 0, 0, 0},
							{1, 1, 0, 1, 1, 0, 1},
							{1, 1, 1, 1, 0, 0, 1},
							{0, 1, 1, 0, 0, 1, 1},
							{1, 0, 1, 1, 0, 1, 1},
							{1, 0, 1, 1, 1, 1, 1},
							{1, 1, 1, 0, 0, 0, 0},
							{1, 1, 1, 1, 1, 1, 1},
							{1, 1, 1, 1, 0, 1, 1}};

bool input[10][7];
int N;

bool backtrack(int countdown, int count, int burnout){
	if (count == N)
		return true;
	for (int i = 0; i < 7; i++){
		if (input[count][i] && (burnout & (1 << i)))
			return false;

		if (digit[countdown][i] != input[count][i]){
			if (digit[countdown][i] && !input[count][i])
				burnout |= (1 << i);
			else
				return false;
		}
	}
	
	if (backtrack(countdown - 1, count + 1, burnout))
			return true;
	return false;
}

int main(){
	while (scanf("%d", &N) && N){
		memset(input, 0, sizeof input);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < 7; j++){
				char ch;
				scanf(" %c", &ch);
				input[i][j] = (ch == 'Y' ? 1 : 0);
			}

		bool match = false;
		for (int i = N - 1; !match && i < 10; i++)
			if (backtrack(i, 0, 0))
					match = true;
		if (match)
			printf("MATCH\n");
		else
			printf("MISMATCH\n");
	}
	return 0;
}
