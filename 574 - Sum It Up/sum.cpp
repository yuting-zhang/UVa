#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

int numbers[15];

int main(){
	int t, n;
	while (scanf("%d %d", &t, &n) == 2 && n != 0){
		printf("Sums of %d:\n", t);
		memset(numbers, 0, sizeof numbers);
		for (int i = 0; i < n; i++)
			scanf("%d", &numbers[i]);

		set<vector<int>> solution;
		int state = 0;
		while (state < (1 << n)){
			int sum = 0;
			for (int i = 0; i < n; i++)
				if (state & (1 << i)){
					sum += numbers[i];
					if (sum > t)
						break;
				}
			if (sum == t){
				vector<int> sol;
				for (int i = 0; i < n; i++)
					if (state & (1 << i))
						sol.push_back(numbers[i]);
				solution.insert(sol);
			}
			state++;	
		}

		if (solution.empty())
			printf("NONE\n");
		for (auto it = solution.rbegin(); it != solution.rend(); it++){
			printf("%d", (*it)[0]);
			for (int i = 1; i < it->size(); i++)
				printf("+%d", (*it)[i]);
			printf("\n");
		}
	}
}
