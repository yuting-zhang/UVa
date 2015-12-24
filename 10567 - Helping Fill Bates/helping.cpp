#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
	string S;
	getline(cin, S);
	int Q;
	scanf("%d\n", &Q);
	
	map<char, vector<int>> mapper;

	for (int i = 0; i < S.size(); i++)
		mapper[S[i]].push_back(i);
	
	while (Q--){
		string SS;
		getline(cin, SS);
		int first = -1, last = -1, index = 0;

		for (int i = 0; i < SS.size(); i++){
			auto it = lower_bound(mapper[SS[i]].begin(), mapper[SS[i]].end(), index);
			if (it == mapper[SS[i]].end())
				break;
			index = *it;
			if (i == 0)
				first = index;
			else if (i == SS.size() - 1)
				last = index;
			index++;
		}

		if (last == -1)
			printf("Not matched\n");
		else
			printf("Matched %d %d\n", first, last);
	}
}
