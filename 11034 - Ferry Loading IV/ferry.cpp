#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int test_case;
	scanf("%d", &test_case);
	while (test_case--){
		int l, m;
		scanf("%d %d ", &l, &m);
		l *= 100;
		queue<int> Queue[2];

		for (int i = 0; i < m; i++){
			string bank;
			int length;
			cin >> length >> bank;
			if (bank == "left")
				Queue[0].push(length);
			else
				Queue[1].push(length);	
		}
		
		int carrier = 0;
		int times = 0, bank = 0;
		while (!Queue[0].empty() || !Queue[1].empty()){
			carrier = 0;
			
			bool loaded = false;
			while (!Queue[bank].empty() && Queue[bank].front() + carrier <= l){
				loaded = true;
				carrier += Queue[bank].front();
				Queue[bank].pop();
			}

			
			times++;
			bank = 1 - bank;
		}
		printf("%d\n", times);
	}
	return 0;
}
