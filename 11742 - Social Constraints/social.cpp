#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

struct constraint_t{
	int a, b, c;
};

int main(){
	int n, m;
	while (scanf("%d %d", &n, &m) && (n || m)){
		vector<constraint_t> constraints(m);
		for (int i = 0; i < m; i++)
			scanf("%d %d %d", &constraints[i].a, &constraints[i].b, &constraints[i].c);
		vector<int> permutation(n);
		for (int i = 0; i < n; i++)
			permutation[i] = i;
		int count = 0;
		do{
			bool ok = true;
			for (int i = 0; i < m; i++){
				if (constraints[i].c > 0){
					if (abs(permutation[constraints[i].a] - permutation[constraints[i].b]) > constraints[i].c){
						ok = false;
						break;
					}
				}else if (constraints[i].c < 0){
				   if (abs(permutation[constraints[i].a] - permutation[constraints[i].b]) < -constraints[i].c){
					   ok = false;
					   break;
				   }
				}
			}
			if (ok)
				count++;
		}while (next_permutation(permutation.begin(), permutation.end()));
		printf("%d\n", count);
	}
	return 0;
}
