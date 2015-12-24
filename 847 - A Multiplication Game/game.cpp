#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <map>

using namespace std;

void init(map<long long, int>& mapper, vector<long long>& seq){
	long long prev = -1;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	int count = 0;
	pq.push(1);
	while (!pq.empty()){
		long long curr = pq.top();
		pq.pop();
		if (curr > 4400000000)
			break;
		if (curr == prev)
			continue;
		mapper[curr] = count++;
		seq.push_back(curr);
		for (int i = 2; i <= 9; i++)
			pq.push(i * curr);
		prev = curr;
	}
}

bool win(long long n, const map<long long, int>& mapper, const vector<long long>& seq){
	vector<bool> state(mapper.size(), false);
	for (int i = state.size() - 1; i >= 1; i--)
		if (seq[i] >= n || !state[i])
			for (int j = 2; j <= 9; j++)
				if (seq[i] % j == 0)
					state[mapper.find(seq[i] / j)->second] = true;
	return state[0];
}

int main(){
	map<long long, int> mapper;
	vector<long long> seq;
	seq.reserve(10000);
	init(mapper, seq);
	long long n;
	while (scanf("%lld", &n) == 1)
		if (win(n, mapper, seq))
			printf("Stan wins.\n");
		else
			printf("Ollie wins.\n");
	return 0;
}
