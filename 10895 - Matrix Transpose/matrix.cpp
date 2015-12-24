#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int main(){
	int m, n;
	while (scanf("%d %d", &m, &n) > 0){
		vector<vector<pair<int, int>>> adjList(n);
		for (int i = 0; i < m; i++){
			int r;
			scanf("%d", &r);
			vector<pair<int, int>> edges(r);
			for (int j = 0; j < r; j++){
				int node;
				scanf("%d", &node);
				edges[j].first = node;
			}
			for (int j = 0; j < r; j++){
				int value;
				scanf("%d", &value);
				edges[j].second = value;
			}
			for (int j = 0; j < r; j++)
				adjList[edges[j].first - 1].push_back({i + 1, edges[j].second});		
		}
		printf("%d %d\n", n, m);
		for (int i = 0; i < n; i++){
			printf("%d", adjList[i].size());
			for (int j = 0; j < adjList[i].size(); j++)
				printf(" %d", adjList[i][j].first);
			printf("\n");
			for (int j = 0; j < adjList[i].size(); j++){
				if (j != 0)
					printf(" ");
				printf("%d", adjList[i][j].second);
			}
			printf("\n");
		}
	}
	return 0;
}
