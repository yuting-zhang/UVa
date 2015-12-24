#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

struct snow_t{
	vector<int> index;
	int curr = 0;
};

int main(){
	int test_case;
	scanf("%d", &test_case);
	while (test_case--){
		int n;
		scanf("%d", &n);
		if (n == 0){
			printf("0\n");
			continue;
		}

		vector<int> flakes;
		flakes.reserve(n);
		map<int, snow_t> mapper;
		for (int i = 0; i < n; i++){
			int snow;
			scanf("%d", &snow);
			mapper[snow].index.push_back(i);
			flakes.push_back(snow);
		}

		int lo = 0, max = 1;
		mapper[flakes[0]].curr++;

		for (int i = 1; i < n; i++){
			auto& value = mapper[flakes[i]];
			if (value.curr != 0 && value.index[value.curr - 1] >= lo){
					max = (i - lo > max ? i - lo : max);
					lo = value.index[value.curr - 1] + 1;
			}
			value.curr++;
		}	
		max = (n - lo > max ? n - lo : max);
		printf("%d\n", max);
	}
	return 0;
}
