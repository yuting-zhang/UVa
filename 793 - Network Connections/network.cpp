#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class UnionFind{
private:
	vector<int> p, rank;

public:
	UnionFind(int sz){
		p.assign(sz, 0);
		rank.assign(sz, 0);
		for (int i = 0; i < sz; i++)
			p[i] = i;
	}

	int findSet(int n){
		return p[n] == n ? n : p[n] = findSet(p[n]);
	}

	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}

	void unionSet(int x, int y){
		if (!isSameSet(x, y)){
			int root_x = findSet(x), root_y = findSet(y);
			if (rank[root_x] > rank[root_y])
				p[root_y] = root_x;
			else{
				p[root_x] = root_y;
				if (rank[root_x] == rank[root_y])
					rank[root_y]++;
			}
		}
	}
};

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		if (i != 0)
			printf("\n");
		int sz;
		scanf("%d\n", &sz);
		UnionFind unionFind(sz);
		string line;
		int success = 0, fail = 0;
		while (getline(cin, line) && !line.empty()){
			istringstream sin(line);
			char ch;
			int c1, c2;
			sin >> ch >> c1 >> c2;
			if (ch == 'c')
				unionFind.unionSet(c1 - 1, c2 - 1);
			else if (unionFind.isSameSet(c1 - 1, c2 - 1))
				success++;
			else
				fail++;
		}
		printf("%d,%d\n", success, fail);
	}
	return 0;
}	
