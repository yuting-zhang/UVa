#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	bool firstCase = true;
	while (scanf("%d", &n) && n){
		if (firstCase)
			firstCase = false;
		else
			printf("\n");
		vector<int> bags(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &bags[i]);

		sort(bags.begin(), bags.end());
		int previous = -1;
		int counter = 0;
		int maxBags = 0;
		for (int i = 0; i < bags.size(); i++)
			if (bags[i] != previous){
				maxBags = max(maxBags, counter);
				previous = bags[i];
				counter = 1;
			}
			else
				counter++;
		maxBags = max(maxBags, counter);

		printf("%d\n", maxBags);
		vector<vector<int>> answer(maxBags);
		for (int i = 0; i < n; i++)
			answer[i % maxBags].push_back(bags[i]);
		for (int i = 0; i < maxBags; i++){
			printf("%d", answer[i].front());
			for (int j = 1; j < answer[i].size(); j++)
				printf(" %d", answer[i][j]);
			printf("\n");
		}
	}
}
