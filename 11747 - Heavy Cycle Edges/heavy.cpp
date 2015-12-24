#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
class UnionFind{
private:
	vector<int> p, rank, setSize;
	int numSets;
public:
	UnionFind(int N){
		setSize.assign(N, 1);
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	int findSet(int i ){
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j){
		if (!isSameSet(i, j)){
			numSets--;
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]){
				p[y] = x; setSize[x] += setSize[y];
			}
			else{
				p[x] = y; setSize[y] += setSize[x];
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
	int numDisjointSets(){
		return numSets;
	}
	int siezOfSet(int i){
		return setSize[findSet(i)];
	}
};

int main(){
	int n, m;
	while (scanf("%d %d", &n, &m) && (n || m)){
		vector<pair<int, ii>> edgeList;
		vector<int> heavy;
		edgeList.reserve(m);
		for (int i = 0; i < m; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			edgeList.push_back({w, {u, v}});
		}
		sort(edgeList.begin(), edgeList.end());
		UnionFind UF(n);
		for (int i = 0; i < m; i++){
			auto front = edgeList[i];
			if (!UF.isSameSet(front.second.first, front.second.second)){
				UF.unionSet(front.second.first, front.second.second);
			}
			else
				heavy.push_back(front.first);
		}
		if (heavy.empty())
			printf("forest\n");
		else{
			for (int i = 0; i < heavy.size(); i++){
				if (i != 0)
					printf(" ");
				printf("%d", heavy[i]);
			}
			printf("\n");
		}
	}
}
