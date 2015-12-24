#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	vector<int> vec;
	while (scanf("%d", &n) > 0){
		vec.push_back(n);
		if (vec.size() % 2){
			nth_element(vec.begin(), vec.begin() + vec.size() / 2, vec.end());
			printf("%d\n", vec[vec.size() / 2]);
		}
		else{
			int sum = 0;
			nth_element(vec.begin(), vec.begin() + vec.size() / 2, vec.end());
			sum += vec[vec.size() / 2];
			nth_element(vec.begin(), vec.begin() + vec.size() / 2 - 1, vec.end());
			sum += vec[vec.size() / 2 - 1];
			printf("%d\n", sum / 2);
		}
	}
	return 0;
}
