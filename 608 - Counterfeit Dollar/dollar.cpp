#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		string left[3], right[3], result[3];
		for (int i = 0; i < 3; i++)
			cin >> left[i] >> right[i] >> result[i];

		char dollar;
		bool light;
		for (dollar = 'A'; dollar <= 'L'; dollar++){
			bool ok;
			for (int weight = 0; weight < 2; weight++){
				if (weight == 0)
					light = true;
				else
					light = false;
				ok = true;

				for (int i = 0; i < 3; i++){
					bool in_left = false, in_right = false;
					for (int j = 0; j < left[i].size(); j++)
						if (left[i][j] == dollar){
							in_left = true;
							break;
						}
						else if (right[i][j] == dollar){
							in_right = true;
							break;
						}
					string expected;
					if (!in_left && !in_right)
						expected = "even";
					else if (in_left && light)
						expected = "down";
					else if (in_left && !light)
						expected = "up";
					else if (in_right && light)
						expected = "up";
					else if (in_right && !light)
 						expected = "down";
					if (expected != result[i]){
						ok = false;
						break;
					}
				}
				if (ok)
					break;
			}
			if (ok)
				break;
		}
		printf("%c is the counterfeit coin and it is %s.\n", dollar, (light ? "light" : "heavy"));
	}
	return 0;
}
