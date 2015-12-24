#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

class UnionFind{
private:
	vector<int> p, rank;
public:
	UnionFind(int N){
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	int findSet(int i){
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i , int j){
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j){
		if (!isSameSet(i, j)){
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y])
				p[y] = x;
			else{
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};

double dist(pair<double, double> p1, pair<double, double> p2){
	return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main(){
	int test_case;
	scanf("%d", &test_case);
	for (int tc = 0; tc < test_case; tc++){
		if (tc != 0)
			printf("\n");
		int n;
		scanf("%d", &n);
		vector<pair<double, double>> coords(n);
		for (int i = 0; i < n; i++){
			scanf("%lf %lf", &coords[i].first, &coords[i].second);
		}
		vector<pair<double, pair<int, int>>> edgeList;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++){
				double distance = dist(coords[i], coords[j]);
				edgeList.push_back({distance, {i, j}});
			}
		sort(edgeList.begin(), edgeList.end());
		double mst_cost = 0;
		UnionFind UF(n);
		for (int i = 0; i < edgeList.size(); i++){
			auto front = edgeList[i];
			if (!UF.isSameSet(front.second.first, front.second.second)){
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		printf("%.2f\n", mst_cost);
	}
	return 0;
}
