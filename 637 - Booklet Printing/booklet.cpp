#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int page;
	while (scanf("%d", &page) && page){
		printf("Printing order for %d pages:\n", page);
		
		int sheets = ceil((double)(page) / 4);
		int head = 1, rear = sheets * 4;

		for (int i = 1; i <= sheets; i++){
			printf("Sheet %d, front: ", i);
			if (rear > page)
				printf("Blank");
			else
				printf("%d", rear);
			printf(", %d\n", head);
			rear--;
			head++;
			if (page >= 2) {
				printf("Sheet %d, back : %d, ", i, head);
				if (rear > page)
					printf("Blank");
				else
					printf("%d", rear);
				printf("\n");
			}
		rear--;
		head++;
		}
	}
	return 0;
}
