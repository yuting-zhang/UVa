#include <cstdio>
#include <cstring>

using namespace std;

int N;
int track[25];

int main(){
	memset(track, 0, sizeof(track));
	while (scanf("%d", &N) == 1){
		int best = 0, best_state = 0;

		int count = 0;
		scanf("%d", &count);

		for (int i = 0; i < count; i++)
			scanf("%d", &track[i]);

		unsigned state = 0;
		while (state < (1 << count)){
			int length = 0;
			for (int i = 0; i < count; i++)
				if (state & (1 << i)){
					if (track[i] + length <= N)
						length += track[i];
					else
						break;
				}
			if (length > best){
				best = length;
				best_state = state;
			}
			state++;
		}

		for (int i = 0; i < count; i++)
			if (best_state & (1 << i))
				printf("%d ", track[i]);
		printf("sum:%d\n", best);
	}
	return 0;
}
