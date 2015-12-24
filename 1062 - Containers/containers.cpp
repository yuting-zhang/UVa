#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(){
	string line;
	int test_case = 0;
	while (getline(cin, line) && line != "end"){
		test_case++;
		vector<stack<char>> stacks;
		for (int i = 0; i < line.size(); i++){
			bool found = false;
			for (int j = 0; j < stacks.size(); j++)
				if (stacks[j].top() >= line[i]){
					stacks[j].push(line[i]);
					found = true;
					break;
				}
			if (!found){
				stack<char> new_stack;
				new_stack.push(line[i]);
				stacks.push_back(new_stack);
			}
		}
		printf("Case %d: %d\n", test_case, stacks.size());
	}	
	return 0;
}
