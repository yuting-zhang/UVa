#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void rotate(vector<vector<char>>& square){
	auto temp = square;
	for (int i = 0; i < square.size(); i++)
		for (int j = 0; j < square.size(); j++)
			temp[i][j] = square[square.size() - 1 - j][i];
	square = temp;
}

int main(){
	int N, n;
	while (scanf("%d %d", &N, &n) && N){
		vector<vector<char>> big(N, vector<char>(N)),
							 small(n, vector<char>(n));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf(" %c ", &big[i][j]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf(" %c ", &small[i][j]);
		int result[4] = {0, 0, 0, 0};
		for (int i = 0; i < 4; i++){
			for (int j = 0; j <= N - n; j++)
				for (int k = 0; k <= N - n; k++){
					bool ok = true;
					for (int r = 0; r < n; r++){
						for (int c = 0; c < n; c++)
							if (big[j + r][k + c] != small[r][c]){
								ok = false;
								break;
							}
						if (!ok)
							break;
					}
					if (ok)
						result[i]++;
				}
			rotate(small);
		}
		printf("%d %d %d %d\n", result[0], result[1], result[2], result[3]);
	}
	return 0;
}
