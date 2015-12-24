#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

struct query_t{
	int num, period, next;
};

bool operator<(const query_t& lhs, const query_t& rhs){
	if (lhs.next < rhs.next)
		return false;
	if (lhs.next == rhs.next && lhs.num < rhs.num)
		return false;
	return true;
}

int main(){
	priority_queue<query_t> system;
	string line;
	while (getline(cin, line) && line != "#"){
		string word;
		istringstream sin(line);
		int num, period;
		sin >> word >> num >> period;
		system.push({num, period, period});
	}

	int K;
	scanf("%d", &K);
	while (K--){
		query_t query = system.top();
		system.pop();
		system.push({query.num, query.period, query.next + query.period});
		printf("%d\n", query.num);
	}
	return 0;
}
