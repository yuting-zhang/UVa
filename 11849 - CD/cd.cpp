#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

int main(){
	int N, M;
	while (scanf("%d %d", &N, &M) && (N || M)){
		set<int> cds;
		while (N--){
			int cd;
			scanf("%d", &cd);
			cds.insert(cd);
		}
		int count = 0;
		while (M--){
			int cd;
			scanf("%d", &cd);
			if (cds.find(cd) != cds.end())
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}
