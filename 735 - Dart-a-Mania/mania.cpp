#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int scores[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
					16, 17, 18, 19, 20, 22, 24, 26, 28, 30, 32, 34, 36,
					38, 40, 21, 27, 33, 39, 42, 45, 48, 51, 54, 57, 60, 
					0, 50};
	
	int value;
	while (scanf("%d", &value) && value > 0){
		int combination = 0, permutation = 0;
		for (int i = 0; i < 43; i++)
			for (int j = 0; j < 43; j++)
				for (int k = 0; k < 43; k++)
					if (scores[i] + scores[j] + scores[k] == value){
						permutation++;
						if (i >= j && j >= k)
							combination++;
					}
		if (permutation == 0)
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", value);
		else{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", value, combination);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", value, permutation);
		}	
		for (int i = 0; i < 70; i++)
			printf("*");
		printf("\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
