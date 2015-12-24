#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

struct common_t{
	vector<int> towers;
	int customers;
};

int main(){
	int n, b;
	int case_no = 0;
	while (scanf("%d %d", &n, &b) && (n || b)){
		case_no++;
		vector<int> towers(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &towers[i]);
		int m;
		scanf("%d", &m);
		vector<common_t> common(m);
		for (int i = 0; i < m; i++){
			int t;
			scanf("%d", &t);
			common[i].towers.assign(t, 0);
			for (int j = 0; j < t; j++)
				scanf("%d", &common[i].towers[j]);
			scanf("%d", &common[i].customers);
		}
		int answer = 0;
		vector<int> locations(b);
		vector<bool> bits(n, false);
		for (int i = 0; i < b; i++)
			bits[i] = true;
		while (true){
			int service = 0;
			for (int i = 0; i < n; i++)
				if (bits[i])
					service += towers[i];
			for (int i = 0; i < m; i++){
				bool first = true;
				for (int j = 0; j < common[i].towers.size(); j++)
					if (bits[common[i].towers[j] - 1]){
						if (first)
							first = false;
						else
							service -= common[i].customers;
					}
			}
			if (service > answer){
				answer = service;
				int index = 0;
				for (int i = 0 ; i < n; i++)
					if (bits[i])
						locations[index++] = i + 1;
			}
			if (!prev_permutation(bits.begin(), bits.end()))
				break;
		}
		printf("Case Number  %d\n", case_no);
		printf("Number of Customers: %d\n", answer);
		printf("Locations recommended:");
		for (int i = 0; i < b; i++)
			printf(" %d", locations[i]);
		printf("\n\n");
	}
	return 0;
}
