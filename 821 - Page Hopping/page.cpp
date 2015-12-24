#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
	int a, b, case_count = 0;
	while (scanf("%d %d", &a, &b) && a && b){
		case_count++;
		vector<pair<int, int>> edges;
		vector<int> hash(110, -1);
		int count = 0;
		
		hash[a] = count++;
		hash[b] = count++;
		edges.push_back({hash[a], hash[b]});

		while (scanf("%d %d", &a, &b) && a && b){
			if (hash[a] == -1)
				hash[a] = count++;
			if (hash[b] == -1)
				hash[b] = count++;
			edges.push_back({hash[a], hash[b]});
		}	
		vector<vector<int>> adjMatrix(count, vector<int>(count, INT_MAX / 2));
		for (int i = 0; i < edges.size(); i++)
			adjMatrix[edges[i].first][edges[i].second] = 1;
		for (int k = 0; k < count; k++)
			for (int i = 0; i < count; i++)
				for (int j = 0; j < count; j++)
					adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
		double total = 0;
		for (int i = 0; i < count; i++)
			for (int j = 0; j < count; j++)
				if (i != j)
					total += adjMatrix[i][j];
		printf("Case %d: average length between pages = %.3f clicks\n", case_count,
				total / ((count - 1) * count));
	}
}
