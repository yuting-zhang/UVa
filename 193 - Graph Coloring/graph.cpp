#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, k;
vector<vector<int>> edges;
vector<int> nodes; // 0 uncolored, 1 black, 2 white

int best;
vector<int> solution;

int curr_best;

void update_best(){
	if (curr_best > best){
		best = curr_best;
		solution.clear();
		for (int i = 0; i < n; i++)
			if (nodes[i] == 1)
				solution.push_back(i + 1);
	}
}

void backtrack(int curr){
	if (curr_best + (n - curr) <= best)
		return;

	if (curr == n){
		update_best();
		return;
	}

	bool canBlack = true;
	for (int dest: edges[curr])
		if (nodes[dest] == 1){
			canBlack = false;
			break;
		}
	if (canBlack){
		nodes[curr] = 1;
		curr_best++;
		backtrack(curr + 1);
		curr_best--;
	}

	nodes[curr] = 2;
	backtrack(curr + 1);
	nodes[curr] = 0;
}

int main(){
	int m;
	scanf("%d", &m);
	while (m--){
		scanf("%d %d", &n, &k);
		edges.assign(n, vector<int>());
		nodes.assign(n, 0);
		best = 0;
		solution.clear();
		curr_best = 0;
		for (int i = 0; i < k; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			a--, b--;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
			
		backtrack(0);
		printf("%d\n", best);
		printf("%d", solution.front());
		for (int i = 1; i < solution.size(); i++)
			printf(" %d", solution[i]);
		printf("\n");
	}
	return 0;
}
