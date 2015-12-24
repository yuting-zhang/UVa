#include <iostream>
#include <cstdio>
#include <vector>
#define CAP 2000000000
using namespace std;

int n, m;
vector<int> vessel;

int simulate(int cap){
	int count = 1;
	int volume = cap;
	for (int i = 0; i < n; i++){
		if (vessel[i] > cap)
			return CAP;
		if (volume >= vessel[i])
			volume -= vessel[i];
		else{
			count++;
			volume = cap - vessel[i];
		}
	}
	return count;
}

int main(){
	while (scanf("%d %d", &n, &m) == 2){
		vessel.assign(n, 0);
		for (int i = 0; i < n; i++)
			scanf("%d", &vessel[i]);
		int solution = CAP;
		int low = 1, high = CAP;
		while (low <= high){
			int mid = (low + high) / 2;
			int result = simulate(mid);
			if (result <= m){
				solution = mid;
				high = mid - 1;
			}else
				low = mid + 1;
		}
		printf("%d\n", solution);
	}
}
