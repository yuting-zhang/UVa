#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

struct dic_type{
	string original;
	string processed;
};

bool operator<(const dic_type& lhs, const dic_type& rhs){
	return lhs.processed < rhs.processed;
}

string process(const string& str){
	string ret;
	for (int i = 0; i < str.size(); i++)
		if (str[i] != ' ')
			ret += str[i];
	return ret;
}

bool operator<(const pair<string, string>& lhs, const pair<string, string>& rhs){
	if (lhs.first < rhs.first)
		return true;
	if (lhs.first == rhs.first && lhs.second < rhs.second)
		return true;
	return false;
}

int main(){
	int T;
	scanf("%d\n\n", &T);
	for (int case_no = 0; case_no < T; case_no++){
		if (case_no)
			printf("\n");
		vector<dic_type> dic;
		string line;
		while (getline(cin, line) && !line.empty()){
			dic_type term;
			term.original = line;
			term.processed = process(line);
			sort(term.processed.begin(), term.processed.end());
			dic.push_back(term);
		}

		sort(dic.begin(), dic.end());

		int begin = 0, end = 0;
		vector<pair<string, string>> answer;

		while (begin < dic.size() && end < dic.size()){
			while (end + 1 < dic.size() && dic[end].processed == dic[end + 1].processed)
				end++;
			for (int i = begin; i < end; i++)
				for (int j = i + 1; j <= end; j++)
					if (dic[i].original < dic[j].original)
						answer.push_back({dic[i].original, dic[j].original});
					else
						answer.push_back({dic[j].original, dic[i].original});
			begin = end = end + 1;
		}
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i].first << " = " << answer[i].second << "\n";	

	}
	return 0;
}
