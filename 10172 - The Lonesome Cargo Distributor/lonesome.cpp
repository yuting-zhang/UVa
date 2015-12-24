#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int input_data(vector<queue<int>>& stations){
	int total = 0;
	for (int i = 0; i < stations.size(); i++){
		int Qi;
		scanf("%d", &Qi);
		total += Qi;
		while (Qi--){
			int cargo_no;
			scanf("%d", &cargo_no);
			stations[i].push(--cargo_no);	
		}
	}
	return total;
}

int main(){
	int SET;
	scanf("%d", &SET);
	while (SET--){
		int N, S, Q;
		scanf("%d %d %d", &N, &S, &Q);
		vector<queue<int>> stations(N);
		int total = input_data(stations);
		int time = 0, location = 0;
		stack<int> carrier;	
		
		while (total){
			while (!carrier.empty()){
				if (carrier.top() == location){
					total--;
					carrier.pop();
					time++;
				}
				else{
					if (stations[location].size() < Q){
						stations[location].push(carrier.top());
						carrier.pop();
						time++;
					}
					else
						break;
				}
			}
			
			while (!stations[location].empty() && carrier.size() < S){
				carrier.push(stations[location].front());
				stations[location].pop();
				time++;
			}
			location = (location + 1) % N;
			time += 2;
		}
		time -= 2;
		printf("%d\n", time);
	}
	return 0;
}

