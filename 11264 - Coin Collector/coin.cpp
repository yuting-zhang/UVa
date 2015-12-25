#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int coins[1005];

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &coins[i]);
		int answer = 0;
		int sum = 0;

		int curr = 0;
		while (curr < n - 1){
			if (sum + coins[curr] < coins[curr + 1]){
				sum += coins[curr];
				answer++;
				curr++;
			}
			else{
				while (curr < n - 1 && sum + coins[curr] >= coins[curr + 1])
					curr++;
				if (curr == n - 1)
					break;
				sum += coins[curr];
				answer++;
				curr++;
			}
		}
		answer++;
		printf("%d\n", answer);
	}
}
