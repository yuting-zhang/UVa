#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int s, d;
	while (scanf("%d %d", &s, &d) == 2){
		size_t state = 0;
		int best = -1;
		while (state < (1 << 12)){
			int month[12];
			for (int i = 0; i < 12; i++)
				if (state & (1 << i))
					month[i] = s;
				else
					month[i] = -d;

			bool ok = true;
			for (int i = 0; true && i < 8; i++){
				int report = 0;
				for (int j = 0; j < 5; j++)
					report += month[i + j];
				if (report > 0)
					ok = false;
			}
			if (ok){
				int total = 0;
				for (int i = 0; i < 12; i++)
					total += month[i];
				if (total > best)
					best = total;
			}
			state++;
		}
		if (best >= 0)
			printf("%d\n", best);
		else
			printf("Deficit\n");
	}
	return 0;
}
