#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n, p;
		scanf("%d %d", &n, &p);
		vector<int> length(p);
		for (int i = 0; i < p; i++)
			scanf("%d", &length[i]);
		bool possible = false;
		for (int i = 0; i < (1 << p); i++){
			int len = 0;
			for (int j = 0; j < p; j++)
				if ((1 << j) & i)
					len += length[j];
			if (len == n){
				possible = true;
				break;
			}
		}
		if (possible)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
