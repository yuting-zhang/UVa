#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>

using namespace std;

class UnionFind{
private:
	vector<int> p, rank, setSize;

public:
	UnionFind(int N){
		p.assign(N, 0);
		rank.assign(N, 0);
		setSize.assign(N, 1);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	
	int findSet(int i){
		return p[i] == i ? i : p[i] = findSet(p[i]);
	}

	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}

	int getSetSize(int i){
		return setSize[findSet(i)];
	}

	void unionSet(int i, int j){
		if (!isSameSet(i, j)){
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]){
				p[y] = x;
				setSize[x] += setSize[y];
			}
			else{
				p[x] = y;
				setSize[y] += setSize[x];
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}	
	}
};

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int F;
		scanf("%d", &F);
		map<string, int> mapper;
		int size = 0;
		UnionFind unionFind(200100);
		while (F--){
			string name1, name2;
			cin >> name1 >> name2;
			if (mapper.find(name1) == mapper.end())
				mapper[name1] = size++;
			if (mapper.find(name2) == mapper.end())
				mapper[name2] = size++;
			unionFind.unionSet(mapper[name1], mapper[name2]);
			printf("%d\n", unionFind.getSetSize(mapper[name1]));
		}
	}
	return 0;
}

