#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct maker_t{
	char name[25] = {0};
	int lo, hi = 0;
};

int main(){
	int T;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++){
		if (tc != 0)
			printf("\n");
		int D;
		scanf("%d", &D);
		vector<maker_t> makers(D);
		for (int i = 0; i < D; i++)
			scanf(" %s %d %d ", makers[i].name, &makers[i].lo, &makers[i].hi);
		int Q;
		scanf("%d", &Q);
		while (Q--){
			int P;
			scanf("%d", &P);
			bool determined = false;
			const char* name = nullptr;
			for (const auto& it: makers)
				if (it.lo <= P && it.hi >= P){
					if (!name){
						determined = true;
						name = &it.name[0]; 
					}
					else
						determined = false;
				}
			if (determined)
				printf("%s\n", name);
			else
				printf("UNDETERMINED\n");
		}
	}
	return 0;
}

