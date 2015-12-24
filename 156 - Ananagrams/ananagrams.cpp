#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct dic_type{
	string original;
	string processed;
};

bool operator<(const dic_type& lhs, const dic_type& rhs){
	return lhs.processed < rhs.processed;
}

int main(){
	vector<dic_type> dic;
	string word;
	while (cin >> word && word != "#"){
		dic_type term;
		term.original = word;
		term.processed = word;
		for (char& it: term.processed)
			if (it >= 'a' && it <= 'z')
				it = it - ('a' - 'A');
		sort(term.processed.begin(), term.processed.end());
		dic.push_back(term);
	}
	sort(dic.begin(), dic.end());
	int index = 0, next_index = 1;
	bool ananagram = true;

	vector<string> answer;
	while (index < dic.size() && next_index <= dic.size()){
		while (next_index < dic.size() && dic[index].processed == dic[next_index].processed){
			if (dic[index].original != dic[next_index].original)
				ananagram = false;
			next_index++;
		}
		if (ananagram)
			answer.push_back(dic[index].original);

		ananagram = true;
		index = next_index;
		next_index++;
	}

	sort(answer.begin(), answer.end());
	for (const auto& it: answer)
		cout << it << "\n";
	return 0;
}

