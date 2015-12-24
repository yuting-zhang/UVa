#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int n, m;
	while (scanf("%d %d", &n, &m) > 0){
		vector<vector<int>> adjList(1000100);
		for (int i = 0; i < n; i++){
			int val;
			scanf("%d", &val);
			adjList[val].push_back(i + 1);
		}
		for (int i = 0; i < m; i++){
			int k, v;
			scanf("%d %d", &k, &v);
			if (adjList[v].size() >= k)
				printf("%d\n", adjList[v][k - 1]);
			else
				printf("0\n");
		}
	}
	return 0;
}
