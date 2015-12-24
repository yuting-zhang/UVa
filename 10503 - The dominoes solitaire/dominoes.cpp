#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dominoes[15][2];
int n, m;
int solution[20][2];
bool taken[15];

bool backtrack(int curr){
	if (curr == n + 1)
		return solution[n][1] == solution[n + 1][0] ? true : false;
	
	for (int i = 0; i < m; i++)
		if (!taken[i]){
			if (solution[curr - 1][1] == dominoes[i][0]){
				solution[curr][0] = dominoes[i][0];
				solution[curr][1] = dominoes[i][1];
				taken[i] = true;
				if (backtrack(curr + 1))
					return true;
				taken[i] = false;
			}else if (solution[curr - 1][1] == dominoes[i][1]){
				solution[curr][0] = dominoes[i][1];
				solution[curr][1] = dominoes[i][0];
				taken[i] = true;
				if (backtrack(curr + 1))
					return true;
				taken[i] = false;
			}
		}
	return false;	
}

int main(){
	while (scanf("%d", &n) && n){
		scanf("%d", &m);
		memset(dominoes, 0, sizeof dominoes);
		memset(solution, 0, sizeof solution);
		memset(taken, false, sizeof taken);

		scanf("%d %d", &solution[0][0], &solution[0][1]);
		scanf("%d %d", &solution[n + 1][0], &solution[n + 1][1]);

		for (int i = 0; i < m; i++)
			scanf("%d %d", &dominoes[i][0], &dominoes[i][1]);

		if (backtrack(1))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
