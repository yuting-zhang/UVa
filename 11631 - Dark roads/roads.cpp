#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void process(int vtx, vector<vector<pair<int, int>>>& adjList, vector<bool>& taken,
			 priority_queue<pair<int, int>>& pq){
	taken[vtx] = true;
	for (int i = 0; i < static_cast<int>(adjList[vtx].size()); i++){
		pair<int, int> v = adjList[vtx][i];
		if (!taken[v.first])
			pq.push({-v.second, -v.first});
	}
}
int main(){
	int m, n;
	while (scanf("%d %d", &m, &n) && (m || n)){
		vector<vector<pair<int, int>>> adjList(m);
		int orig_cost = 0;
		for (int i = 0; i < n; i++){
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			adjList[x].push_back({y, z});
			adjList[y].push_back({x, z});
			orig_cost += z;
		}
		priority_queue<pair<int, int>> pq;
		vector<bool> taken(m, false);
		process(0, adjList, taken, pq);
		int mst_cost = 0;
		while (!pq.empty()){
			pair<int, int> front = pq.top();
			pq.pop();
			int u = -front.second, v = -front.first;
			if (!taken[u]){
				mst_cost += v;
				process(u, adjList, taken, pq);
			}
		}
		printf("%d\n", orig_cost - mst_cost);
	}
	return 0;
}
