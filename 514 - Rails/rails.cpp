#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(){
	int N;
	while (scanf("%d", &N) && N){
		while (true){
			int order;
			scanf("%d", &order);
			if (order == 0)
				break;
			stack<int> station;
			int coach = 1;

			bool ok = true;
			for (int i = 0; i < N; i++){
				if (i != 0)
					scanf("%d", &order);
				bool possible = false;
				while (ok){
					if (!station.empty() && station.top() == order){
						station.pop();
						possible = true;
						break;
					}
					if (coach == order){
						coach++;
						possible = true;
						break;
					}
					if (coach >= N)
						break;
					station.push(coach++);
				}
				if (!possible)
					ok = false;

			}
			if (ok)
				printf("Yes\n");
			else
				printf("No\n");
		}
		printf("\n");
	}
	return 0;
}
