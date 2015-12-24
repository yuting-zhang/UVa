#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int f, r;
	while (scanf("%d %d", &f, &r) == 2){
		int front[15], rear[15];
		for (int i = 0; i < f; i++)
			scanf("%d", &front[i]);
		for (int i = 0; i < r; i++)
			scanf("%d", &rear[i]);
		double ratio[110];
		int index = 0;
		for (int i = 0; i < f; i++)
			for (int j = 0; j < r; j++)
				ratio[index++] = (double)front[i]/rear[j];
		sort(ratio, ratio + index);
		double spread = 0;
		for (int i = 0; i < index - 1; i++){
			double val = ratio[i + 1] / ratio[i];
			if (val > spread)
				spread = val;
		}
		printf("%.2f\n", spread);
	}
	return 0;
}
