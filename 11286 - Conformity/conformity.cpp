#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int n;
	while (scanf("%d", &n) && n){
		map<unsigned long long, int> mapper;
		while (n--){
			int course[5];
			for (int i = 0; i < 5; i++)
				scanf("%d", &course[i]);
			sort(course, course + 5);
			unsigned long long code = 0;
			for (int i = 0; i < 5; i++)
				code += course[i] * pow(10, i * 2);
			mapper[code]++;
		}
		int pop = 0;
		for (const auto& it: mapper)
			pop = max(it.second, pop);
		int count = 0;
		for (const auto& it: mapper)
			if (it.second == pop)
			   count += pop;	
		printf("%d\n", count);
	}
	return 0;
}
