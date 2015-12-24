#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string line;
	while (getline(cin, line) && !line.empty()){
		istringstream sin(line);
		vector<int> pancake;
		pancake.reserve(40);
		int cake;
		while (sin >> cake)
			pancake.push_back(cake);
		int curr = pancake.size();
		vector<int> sorted = pancake;
		sort(sorted.begin(), sorted.end());
		for (int i = 0 ; i < pancake.size() - 1; i++)
			printf("%d ", pancake[i]);
		printf("%d\n", pancake.back());
		while (curr > 0){ 
			auto it = find(pancake.begin(), pancake.end(), sorted[curr - 1]);
			if (it - pancake.begin() != curr - 1){
				if (it - pancake.begin() != 0){
					printf("%d ", pancake.size() - (it - pancake.begin()));
					reverse(pancake.begin(), it + 1);
				}
				printf("%d ", pancake.size() + 1 - curr);
				reverse(pancake.begin(), pancake.begin() + curr);
			}
			curr--;
		}
		printf("0\n");
	}
	return 0;
}
