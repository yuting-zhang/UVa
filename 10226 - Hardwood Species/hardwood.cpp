#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main(){
	int test_case;
	scanf("%d\n\n", &test_case);
	for (int case_no = 0; case_no < test_case; case_no++){
		if (case_no != 0)
			printf("\n");
		map<string, int> trees;
		string line;
		int total = 0;
		while (getline(cin, line) && !line.empty())
			trees[line]++, total++;
		for (auto it = trees.begin(); it != trees.end(); it++)
			printf("%s %.4f\n", it->first.c_str(), static_cast<double>(it->second) / total * 100);
	}
	return 0;
}
