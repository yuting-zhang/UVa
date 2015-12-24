#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int n, m;
	while (scanf("%d", &n) == 1){
		scanf("%d", &m);
		vector<int> number(m);
		for (int i = 0; i < m; i++)
			scanf("%d", &number[i]);
		vector<bool> state(n + 1, false);
		for (int i = 0; i <= n; i++)
			for (int j = 0; j < m; j++)
				if (i + number[j] <= n)
					if (!state[i])
						state[i + number[j]] = true;
		if (state[n])
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}
	return 0;
}
