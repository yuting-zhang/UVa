#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void process(const string& source, const string& target, int src_index, int tgt_index,
			 string curr_string, string curr_result, 
			 stack<char>& stk, vector<string>& result)
{
	if (curr_string == target){
		result.push_back(curr_result);
		return;
	}
	
	if (!stk.empty() && stk.top() == target[tgt_index]){
		char ch = stk.top();
		stk.pop();
		process(source, target, src_index, tgt_index + 1, curr_string + ch, curr_result + 'o', stk, result);
		stk.push(ch);
	}

	if (src_index < source.size()){
		stk.push(source[src_index]);
		process(source, target, src_index + 1, tgt_index, curr_string, curr_result + 'i', stk, result);
		stk.pop();
	}
}

int main(){
	string source, target;
	while(getline(cin, source)){
		getline(cin, target);
		stack<char> stk;
		vector<string> result;
		process(source, target, 0, 0, "", "", stk, result);
		sort(result.begin(), result.end());
		printf("[\n");
		for (int i = 0; i < result.size(); i++){
			for (int j = 0; j < result[i].size() - 1; j++)
				printf("%c ", result[i][j]);
			printf("%c\n", result[i].back());
		}
		printf("]\n");
	}
	return 0;
}
