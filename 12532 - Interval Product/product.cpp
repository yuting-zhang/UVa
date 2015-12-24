#include <iostream>
#include <cstdio>
#include <vector>
#define LSOne(i) (i & (-i))
using namespace std;

class FenwickTree{
private:
	vector<int> ft;

public:
	FenwickTree(int n){
		ft.assign(n + 1, 0);
	}
	int rsq(int b){
		int sum = 0;
		while(b){
			sum += ft[b];
			b -= LSOne(b);
		}
		return sum;
	}
	int rsq(int a, int b){
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}
	void adjust(int k, int v){
		while (k < ft.size()){
			ft[k] += v;
			k += LSOne(k);
		}
	}
};

int calc(int i){
	if (i > 0)
		return 1;
	if (i == 0)
		return 0;
	return -1;
}

int main(){
	int N, K;
	while (scanf("%d %d", &N, &K) == 2){
		FenwickTree zero(N), minus(N);
		vector<int> A(N + 1);
		for (int i = 0; i < N; i++){
			int val;
			scanf("%d", &val);
			if (val == 0)
				zero.adjust(i + 1, 1);
			else if (val < 0)
				minus.adjust(i + 1, 1);
			A[i + 1] = val;
		}
		for (int i = 0; i < K; i++){
			char cmd;
			int a, b;
			scanf(" %c %d %d", &cmd, &a, &b);
			if (cmd == 'C'){
				if (calc(A[a]) != calc(b)){
					if (A[a] == 0)
						zero.adjust(a, -1);
					else if (A[a] < 0)
						minus.adjust(a, -1);
					if (b == 0)
						zero.adjust(a, 1);
					else if (b < 0)
						minus.adjust(a, 1);
					A[a] = b;
				}
			}else{
				int zero_val = zero.rsq(a, b),
					minus_val = minus.rsq(a, b);
				if (zero_val > 0)
					printf("0");
				else if (minus_val % 2 == 0)
					printf("+");
				else
					printf("-");
			}
		}
		printf("\n");
	}
	return 0;
}
