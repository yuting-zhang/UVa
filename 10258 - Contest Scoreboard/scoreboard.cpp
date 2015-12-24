#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

struct contestant_t{
	contestant_t(){
		memset(solved, false, sizeof(solved));
		memset(penalty, 0, sizeof(penalty));
		submitted = false;
	}

	bool solved[9];
	int penalty[9];
	bool submitted;
	int id;
	
	int solved_cnt() const{
		int ret = 0;
		for (int i = 0; i < 9; i++)
			if (solved[i])
	   			ret++;
		return ret;
	}

	int penalty_cnt() const{
		int ret = 0;
		for (int i = 0; i < 9; i++)
			if (solved[i])
				ret += penalty[i];
		return ret;
	}
};

bool cmp(const contestant_t& lhs, const contestant_t& rhs){
	if (!lhs.submitted)
		return false;
	if (!rhs.submitted)
		return true;

	int lhs_solved = lhs.solved_cnt(), rhs_solved = rhs.solved_cnt();
	if (lhs_solved > rhs_solved)
		return true;
	else if (lhs_solved == rhs_solved){
		int lhs_time = lhs.penalty_cnt(), rhs_time = rhs.penalty_cnt();
		if (lhs_time < rhs_time)
			return true;
		else if (lhs_time == rhs_time)
			return lhs.id < rhs.id;
	}
	return false;
}

int main(){
	int n;
	scanf("%d\n", &n);
	for (int case_no = 0; case_no < n; case_no++){
		if (case_no != 0)
			printf("\n");
		scanf("\n");
		string line;
		vector<contestant_t> contestants(100);
		for (int i = 0; i < 100; i++)
			contestants[i].id = i + 1;

		while (getline(cin, line) && !line.empty()){
			istringstream sin(line);
			int contestant, problem, time;
			char verdict;
			sin >> contestant >> problem >> time >> verdict;
			contestant--;
			problem--;
			contestants[contestant].submitted = true;
			if (contestants[contestant].solved[problem])
				continue;
			if (verdict == 'I')
				contestants[contestant].penalty[problem] += 20;
			else if (verdict == 'C'){	
				contestants[contestant].solved[problem] = true;
				contestants[contestant].penalty[problem] += time;
			}
		}

		sort(contestants.begin(), contestants.end(), cmp);
		for (int i = 0; i < contestants.size(); i++){
			if (!contestants[i].submitted)
				break;
			printf("%d %d %d\n", contestants[i].id, contestants[i].solved_cnt(), contestants[i].penalty_cnt());
		}
	}
	return 0;
}
