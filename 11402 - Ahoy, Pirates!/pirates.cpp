#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class SegmentTree{
private:
	vector<int> st, lazy; // -1: no pending update, 0: to Barbery, 1: to Buccaneer, 2: to inverse  
	const vector<int>& A;
	int n;

	int left(int p){
		return p << 1;
	}

	int right(int p){
		return (p << 1) + 1;
	}

	void build(int p, int L, int R){
		if (L == R)
			st[p] = A[L];
		else{
			build(left(p), L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);
			st[p] = st[left(p)] + st[right(p)];
		}		
	}

	int updateLazy(int old, int query){
		if (old == -1)
			return query;
		if (query == -1)
			return old;
		if (old == 2 && query == 2)
			return -1;
		if (query == 2)
			return 1 - old;
		return query;
	}

	void applyLazy(int p, int L, int R){
		if (lazy[p] == 0)
			st[p] = 0;
		else if (lazy[p] == 1)
			st[p] = R - L + 1;
		else if (lazy[p] == 2)
			st[p] = R - L + 1 - st[p];
		if (L != R){
			lazy[left(p)] = updateLazy(lazy[left(p)], lazy[p]);
			lazy[right(p)] = updateLazy(lazy[right(p)], lazy[p]);
		}
		lazy[p] = -1;
	}

	int update(int p, int L, int R, int i, int j, int query){
		applyLazy(p, L, R);

		if (L > j || R < i)
			return st[p];
		
		if (L >= i && R <= j){
			lazy[p] = query;
			applyLazy(p, L, R);
			return st[p];
		}
		
		return st[p] = update(left(p), L, (L + R) / 2, i, j, query) + 
				 	   update(right(p), (L + R) / 2 + 1, R, i, j, query);
	}

	int rsq(int p, int L, int R, int i, int j){
		if (L > j || R < i)
			return 0;
		
		applyLazy(p, L, R);
		if (L >= i && R <= j)
			return st[p];

		return rsq(left(p), L, (L + R) / 2, i, j) + 
			   rsq(right(p), (L + R) / 2 + 1, R, i, j);
	}

public:
	SegmentTree(const vector<int>& newA): A(newA){
		n = newA.size();
		st.assign(n * 4, 0);
		lazy.assign(n * 4, -1);
		build(1, 0, n - 1);
	}

	void update(int i, int j, int query){
		update(1, 0, n - 1, i, j, query);
	}

	int rsq(int i, int j){
		return rsq(1, 0, n - 1, i, j);
	}
};

int main(){
	int TC;
	scanf("%d", &TC);
	for (int case_no = 0; case_no < TC; case_no++){
		printf("Case %d:\n", case_no + 1);
		int M;
		scanf("%d", &M);
		vector<int> A;
		A.reserve(1100000);
		while (M--){
			char st[100];
			int T;
			scanf(" %d %s ", &T, &st);
			for (int i = 0; i < T; i++){
				char* ch = st;
				while (*ch){
					A.push_back(*ch - '0');
					ch++;
				}
			}
		}
		SegmentTree st(A);
		int Q;
		scanf("%d", &Q);
		int count = 0;
		while (Q--){
			char query;
			int a, b;
			scanf(" %c %d %d ", &query, &a, &b);
			if (query == 'F')
				st.update(a, b, 1);
			else if (query == 'E')
				st.update(a, b, 0);
			else if (query == 'I')
				st.update(a, b, 2);
			else if (query == 'S')
				printf("Q%d: %d\n", ++count, st.rsq(a, b));
		}
	}
	return 0;
}
