#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;

int main(){
	int B, S;
	int counter = 0;
	while (scanf("%d %d", &B, &S) && B && S){
		counter++;
		printf("Case %d: ", counter);
		vector<int> bachelor(B);
		int youngest = INT_MAX;
		for (int i = 0; i < B; i++){
			scanf("%d", &bachelor[i]);
			youngest = min(youngest, bachelor[i]);
		}
		int temp;
		for (int i = 0; i < S; i++)
			scanf("%d", &temp);
		if (B <= S)
			printf("0\n");
		else
			printf("%d %d\n", B - S, youngest);
	}
}
