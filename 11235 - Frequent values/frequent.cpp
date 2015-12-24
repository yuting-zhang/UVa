#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <map>
#include <cmath>

using namespace std;

class SegmentTree{
private:
	vector<int> A;
	vector<pair<int, int>> st;	
	map<int, pair<int, int>> range;
 

	int left(int n){
		return n << 1;
	}

	int right(int n){
		return (n << 1) + 1;
	}

	int getFreq(int val, int L, int R){
		pair<int, int> bounds = range[val];
		if (bounds.first > R || bounds.second < L)
			return 0;
		if (L < bounds.first)
			L = bounds.first;
		if (R > bounds.second)
			R = bounds.second;
		return R - L + 1;
	}

	void build(int p, int L, int R){
		if (L == R){
			st[p].first = L;
			st[p].second = 1;
			return;
		}
		
		build(left(p), L, (L + R) / 2);
		build(right(p), (L + R) / 2 + 1, R);

		pair<int, int> p1 = st[left(p)], p2 = st[right(p)];
		if (A[p1.first] == A[p2.first]){
			st[p] = make_pair(p1.first, p1.second + p2.second);
			return;
		}

		pair<int, int> p3 = make_pair(0, 0);
		if (A[(L + R)/ 2] == A[(L + R) / 2 + 1])
			p3 = make_pair((L + R) / 2, getFreq(A[(L + R) / 2], L, R));

		if (p1.second >= p2.second && p1.second >= p3.second)
			st[p] = p1;
		else if (p2.second >= p1.second && p2.second >= p3.second)
			st[p] = p2;
		else
			st[p] = p3;
	}
	
	pair<int,int> rmq(int p, int L, int R, int i, int j){
		if (L > j || R < i)
			return make_pair(0, -1);
		if (L >= i && R <= j)
			return st[p];

		pair<int, int> p1 = rmq(left(p), L, (L + R) / 2, i, j),
	   				   p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

		if (p1.second == -1)
			return p2;
		if (p2.second == -1)
			return p1;

		if (A[p1.first] == A[p2.first])
			return make_pair(p1.first, p1.second + p2.second);

		pair<int, int> p3 = make_pair(0, 0);
		if (A[(L + R)/ 2] == A[(L + R) / 2 + 1])
			p3 = make_pair((L + R) / 2, getFreq(A[(L + R) / 2], max(i, L), min(j, R)));

		if (p1.second >= p2.second && p1.second >= p3.second)
			return p1;
		else if (p2.second >= p1.second && p2.second >= p3.second)
			return p2;
		else
			return p3;
	}

public:
	SegmentTree(vector<int> newA){
		A = newA;
		st.assign(A.size() * 4, {0, -1});
		int left = 0, right = 0, prev = A[0];
		for (int i = 1; i < A.size(); i++)
			if (A[i] != prev){
				right = i - 1;
				range[prev] = make_pair(left, right);
				left = i;
				prev = A[i];
			}
		range[prev] = make_pair(left, A.size() - 1);
		build(1, 0, A.size() - 1);
	}

	int rmq(int i, int j){
		return rmq(1, 0, A.size() - 1, i, j).second;
	}
};

int main(){
	int n;
	while (scanf("%d", &n) && n){
		int q;
		scanf("%d", &q);
		vector<int> A(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		SegmentTree st(A);
		while (q--){
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n", st.rmq(l - 1, r - 1));
		}	
	}
	return 0;
}
