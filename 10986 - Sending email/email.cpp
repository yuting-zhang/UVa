#include <iostream>
#include <cstdio>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> ii;

int main(){
	int N;
	scanf("%d", &N);
	for (int case_no = 1; case_no <= N; case_no++){
		int n, m, S, T;
		scanf("%d %d %d %d", &n, &m, &S, &T);
		vector<vector<ii>> nodes(n);
		for (int i = 0; i < m; i++){
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			nodes[x].push_back({y, z});
			nodes[y].push_back({x, z});
		}
		vector<int> dist(n, INT_MAX);
		dist[S] = 0;
		queue<int> q;
		vector<bool> visited(n, false);
		q.push(S);
		visited[S] = true;
		while (!q.empty()){
			int front = q.front();
			q.pop();
			visited[front] = false;
			for (int i = 0; i < nodes[front].size(); i++){
				ii edge = nodes[front][i];
				if (dist[front] + edge.second < dist[edge.first]){
					dist[edge.first] = dist[front] + edge.second;
					if (!visited[edge.first]){
						q.push(edge.first);
						visited[edge.first] = true;
					}
				}
			}
			
		}
		printf("Case #%d: ", case_no);
		if (dist[T] != INT_MAX)
			printf("%d\n", dist[T]);
		else
			printf("unreachable\n");
	}
	return 0;
}
