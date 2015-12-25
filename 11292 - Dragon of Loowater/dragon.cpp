#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	while (scanf("%d %d", &n, &m) == 2 && n && m){
		vector<int> heads(n);
		vector<int> knights(m);
		for (int i = 0; i < n; i++)
			scanf("%d", &heads[i]);
		for (int i = 0; i < m; i++)
			scanf("%d", &knights[i]);
		sort(heads.begin(), heads.end());
		sort(knights.begin(), knights.end());
		int knight = 0;
		bool doomed = false;
		int gold = 0;
		for (int i = 0; i < n; i++){
			if (m - knight < n - i){
				doomed = true;
				break;
			}
			while (knights[knight] < heads[i]){
				knight++;
				if (knight == m){
					doomed = true;
					break;
				}
			}
			if (doomed)
				break;
			gold += knights[knight];
			knight++;
		}
		if (doomed)
			printf("Loowater is doomed!\n");
		else
			printf("%d\n", gold);
	}
}
