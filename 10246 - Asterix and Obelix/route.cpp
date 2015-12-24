#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vector<ii>> vvii;

void Dijkstra(int source, vi& dist, vvii& adjList, vector<int>& city){	
	for (int i = 0; i < dist.size(); i++)
		dist[i] = INT_MAX / 3;
	dist[source] = 0;
	int C = dist.size();
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({0, source});

	while (!pq.empty()){
		ii front = pq.top();pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		for (int j = 0; j < (int)adjList[u].size(); j++){
			ii v = adjList[u][j];
			if (city[v.first] > city[source])
				continue;
			if (dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				pq.push({dist[v.first], v.first});
			}
		}
	}
}
int main(){
	int C, R, Q;
	int case_no = 0;
	while (scanf("%d %d %d", &C, &R, &Q) && (C || R || Q)){
		case_no++;
		if (case_no != 1)
			printf("\n");
		printf("Case #%d\n", case_no);
		vvii adjList(C);
		vvi dist(C, vi(C, INT_MAX / 3));

		vector<int> city(C, 0);
		for (int i = 0; i < C; i++){
			scanf("%d", &city[i]);
			dist[i][i] = 0;
		}

		for (int i = 0; i < R; i++){
			int c1, c2, d;
			scanf("%d %d %d", &c1, &c2, &d);
			c1--; c2--;
			adjList[c1].push_back({c2, d});
			adjList[c2].push_back({c1, d});
		}

		for (int i = 0; i < C; i++){
			vector<int> result(C);
			Dijkstra(i, result, adjList, city);	
			for (int j = 0; j < C; j++)
				for (int k = 0; k < C; k++)
					dist[j][k] =  min(dist[j][k], result[j] + result[k] + city[i]);
		}


		for (int i = 0; i < Q; i++){
			int c1, c2;
			scanf("%d %d", &c1, &c2);
			c1--; c2--;
			if (dist[c1][c2] < INT_MAX / 3)
				printf("%d\n", dist[c1][c2]);
			else
				printf("-1\n");
		}
	}
}
	
