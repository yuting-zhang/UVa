#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++){
		int N;
		scanf("%d", &N);
		bool covered[105];
		memset(covered, false, sizeof covered);
		for (int i = 0; i < N; i++){
			char ch;
			scanf(" %c ", &ch);
			covered[i] = (ch == '#');
		}
		int count = 0;
		for (int i = 0; i < N; i++)
			if (!covered[i]){
				count++;
				covered[i] = true;
				covered[i + 1] = true;
				covered[i + 2] = true;
			}
		printf("Case %d: %d\n", tc + 1, count);
	}
}
