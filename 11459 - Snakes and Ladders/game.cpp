#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	int case_no;
	scanf("%d", &case_no);
	while (case_no--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vector<int> player(a, 0);
		vector<int> map(100, -1);

		for (int i = 0; i < b; i++){
			int begin, end;
			scanf("%d %d", &begin, &end);
			map[--begin] = --end;
		}

		int round = 0;
		bool game = true;	
		for (int i = 0; i < c; i++){
			int roll;
			scanf("%d", &roll);
			if (!game)
				continue;
			player[round] += roll;
			if (player[round] >= 99)
				player[round] = 99;
			if (map[player[round]] != -1)
				player[round] = map[player[round]];
			if (player[round] == 99)
				game = false;
			round = (round + 1) % a;
		}

		for (int i = 0; i < a; i++)	
			printf("Position of player %d is %d.\n", i + 1, player[i] + 1);
	}	
	return 0;
}
