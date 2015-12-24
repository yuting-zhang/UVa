#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, M;
vector<vector<int>> diagonal;

int getIndex(int row, int col){
	return col + N - 1 - row;
}

int main(){
	while (scanf("%d %d", &N, &M) && N && M){
		diagonal.assign(N + M + 1, vector<int>());
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++){
				int data;
				scanf("%d", &data);
				diagonal[getIndex(i, j)].push_back(data);
			}


		int Q;
		scanf("%d", &Q);
		while (Q--){
			int L, U;
			scanf("%d %d", &L, &U);
			int solution = 0;
			for (int i = 0; i < N + M - 1; i++){
				auto lower = lower_bound(diagonal[i].begin(), diagonal[i].end(), L);
				auto upper = upper_bound(diagonal[i].begin(), diagonal[i].end(), U);
				int length = upper - lower;
				solution = max(length, solution);
			}
			printf("%d\n", solution);
		}
		printf("-\n");
	}
}
