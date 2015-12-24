#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int num;
	while (scanf("%d", &num) && num){
		int time = 500;
		vector<int> lights;
		do{
			num *= 2;
			lights.push_back(num);
			time = min(time, num);
		}while (scanf("%d", &num) && num);

		while (time <= 18000){
			bool green = true;
			for (int i = 0; i < lights.size(); i++)
				if (time % lights[i] >= lights[i] / 2 - 5){
					green = false;
			  		break;
				}
			if (green)
				break;	
			time++;
		}
		if (time <= 18000){
			int hour = time / 3600,
				minute = time % 3600 / 60,
				second = time % 60;
			printf("0%d:", hour);
			if (minute < 10)
				printf("0");
			printf("%d:", minute);
			if (second < 10)
				printf("0");
			printf("%d\n", second);
		}
		else
			printf("Signals fail to synchronise in 5 hours\n");
	}
	scanf("%d%d", &num, &num);
	return 0;
}
