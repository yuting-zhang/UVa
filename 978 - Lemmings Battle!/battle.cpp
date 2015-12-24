#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	for (int test_case = 0; test_case < N; test_case++){
		if (test_case != 0 )
			printf("\n");

		int B, SG, SB;
		scanf("%d %d %d", &B, &SG, &SB);
		multiset<int> green, blue;
		for (int i = 0; i < SG; i++){
			int power;
			scanf("%d", &power);
			green.insert(power);
		}
		for (int i = 0; i < SB; i++){
			int power;
			scanf("%d", &power);
			blue.insert(power);
		}

		while (!green.empty() && !blue.empty()){
			vector<int> green_s(B, -1), blue_s(B, -1);
			for (int i = 0; i < B; i++){
				if (green.empty() || blue.empty())
					break;
				else{
					green_s[i] = *green.rbegin(),
					blue_s[i] = *blue.rbegin();
					green.erase(--green.end());
					blue.erase(--blue.end());
				}
			}
			for (int i = 0; i < B; i++)
				if (green_s[i] == -1 || blue_s[i] == -1)
					break;
				else{
					if (green_s[i] > blue_s[i])
						green.insert(green_s[i] - blue_s[i]);
					else if (green_s[i] < blue_s[i])
						blue.insert(blue_s[i] - green_s[i]);
				}
		}
		
		if (green.empty() && blue.empty())
			printf("green and blue died\n");
		else if (green.empty()){
			printf("blue wins\n");
			for (auto it = blue.rbegin(); it != blue.rend(); it++)
				printf("%d\n", *it);
		}
		else{
			printf("green wins\n");
			for (auto it = green.rbegin(); it != green.rend(); it++)
				printf("%d\n", *it);
		}
	}
	return 0;
}
