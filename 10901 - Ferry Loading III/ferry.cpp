#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

/* I didn't notice "arrival times for each test case are strictly increasing" in the problem statement.
 * So the two sortings and some handlings can be deleted from the following code.
 * I am just too lazy to change that anyway lol.
 */

struct car_t{
	int arrive_time;
	int id;
	int bank;
	int departure_time;
};

int main(){
	int test_case;
	scanf("%d", &test_case);
	for (int case_no = 0; case_no < test_case; case_no++){
		if (case_no != 0)
			printf("\n");

		int n, t, m;
		scanf("%d %d %d", &n, &t, &m);
		vector<car_t> car_vec(m);
		queue<car_t*> Queue[2];

		for (int i = 0; i < m; i++){
			string bank;
			car_t& car = car_vec[i];
			car.id = i;
			cin >> car.arrive_time >> bank;
			if (bank == "left")
				car.bank = 0;
			else
				car.bank = 1;	
		}
		
		sort(car_vec.begin(), car_vec.end(), [](const car_t& lhs, const car_t& rhs)
				{return lhs.arrive_time < rhs.arrive_time;});

		for (int i = 0; i < m; i++)
			Queue[car_vec[i].bank].push(&car_vec[i]);

		vector<car_t*> carrier;
		int time = 0, bank = 0;
		while (!Queue[0].empty() || !Queue[1].empty() || !carrier.empty()){
			while (!carrier.empty()){
				carrier.back()->departure_time = time;
				carrier.pop_back();
			}
			
			if (Queue[0].empty() && Queue[1].empty())
				break;
			bool loaded = false;
			while (!Queue[bank].empty() && Queue[bank].front()->arrive_time <= time && carrier.size() < n){
				loaded = true;
				carrier.push_back(Queue[bank].front());
				Queue[bank].pop();
			}

			if (loaded){
				time += t;
				bank = 1 - bank;
			}
			else{
				if (!Queue[1 - bank].empty() && Queue[1 - bank].front()->arrive_time <= time){
					time += t;
					bank = 1 - bank;
				}else{
					if (Queue[0].empty())
						time = Queue[1].front()->arrive_time;
					else if (Queue[1].empty())
						time = Queue[0].front()->arrive_time;
					else
						time = min(Queue[0].front()->arrive_time, Queue[1].front()->arrive_time);
				}
			}
		}
		sort(car_vec.begin(), car_vec.end(), [](const car_t& lhs, const car_t& rhs)
				{return lhs.id < rhs.id;});
		for (int i = 0; i < m; i++)
			printf("%d\n", car_vec[i].departure_time);
	}
	return 0;
}
