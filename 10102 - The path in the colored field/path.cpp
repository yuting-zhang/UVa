#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#include <climits>

using namespace std;

int main(){
	int M;
	while (scanf("%d", &M) == 1){
		vector<pair<int, int>> ones, threes;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++){
				char ch;
				scanf(" %c ", &ch);
				if (ch == '1')
					ones.push_back(make_pair(i, j));
				if (ch == '3')
					threes.push_back(make_pair(i, j));
			}
		int path = 0;
		for (const auto& one: ones){
			int n_path = INT_MAX;
			for (const auto& three: threes)
				n_path = min(n_path ,static_cast<int>(abs(one.first - three.first) + 
											      abs(one.second - three.second)));
			path = max(path, n_path);
		}
		printf("%d\n", path);
	}
	return 0;
}
