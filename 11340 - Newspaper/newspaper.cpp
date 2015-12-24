#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	while (N--){
		int K;
		scanf("%d\n", &K);
		int map[256];
		memset(map, 0, sizeof(map));
		while (K--){
			unsigned char ch;
			int cents;
			scanf("%c %d\n", &ch, &cents);
			map[ch] = cents;
		}
		int M;
		scanf("%d\n", &M);
		long long cents = 0;
	
		while (M){
			unsigned char ch;
			scanf("%c", &ch);
			cents += map[ch];
			if (ch == '\n')
				M--;
		}
		printf("%.2f$\n", (double)cents / 100);
	}
	return 0;
}
