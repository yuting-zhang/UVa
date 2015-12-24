#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int N;
	while (scanf("%d", &N) > 0){
		vector<int> weight(pow(2, N));
		for (int i = 0; i < weight.size(); i++)
			scanf("%d", &weight[i]);
		vector<int> sum(weight.size(), 0);
		for (int i = 0; i < weight.size(); i++)
			for (int j = 0; j < N; j++)
				sum[i] += weight[i ^ (1 << j)];

		int answer = 0;
		for (int i = 0; i < weight.size() - 1; i++)
			for (int j = i + 1; j < weight.size(); j++)
				if ((((i ^ j) - 1) & (i ^ j)) == 0 
					&& sum[i] + sum[j] > answer)
					answer = sum[i] + sum[j];
		printf("%d\n", answer);
	}
	return 0;
}
