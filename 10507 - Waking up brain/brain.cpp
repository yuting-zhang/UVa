#include <iostream>
#include <cstdio>
#include <list>
#include <cstring>
#include <utility>

using namespace std;

int main(){
	int N, M;
	while (scanf("%d %d", &N, &M) > 0){
		bool awake[26];
		memset(awake, false, sizeof(awake));
		for (int i = 0; i < 3; i++){
			char ch;
			scanf(" %c ", &ch);
			awake[ch - 'A'] = true;
		}
		int count = 3;
		list<pair<int, int>> connections;
		for (int i = 0; i < M; i++){
			char ch1, ch2;
			scanf(" %c %c ", &ch1, &ch2);
			connections.push_back({ch1 - 'A', ch2 - 'A'});
		}
		bool brain_dead = false;
		int years = 0;
		while (count < N && !brain_dead){
			auto it = connections.begin();
			bool changed = false;
			int active[26];
			memset(active, 0, sizeof(active));
			while (it != connections.end()){
				if (awake[it->first])
					active[it->second]++;
				if (awake[it -> second])
					active[it->first]++;
				it++;
			}

			for (int i = 0; i < 26; i++)
				if (active[i] >= 3 && !awake[i]){
					awake[i] = true;
					changed = true;
					count++;
				}

			years++;
			if (!changed)
				brain_dead = true;
		}
		if (brain_dead)
			printf("THIS BRAIN NEVER WAKES UP\n");
		else
			printf("WAKE UP IN, %d, YEARS\n", years);
	}
	return 0;
}
