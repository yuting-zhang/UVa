#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int get(int x, int y, int length){
	return x + y * length;
}

int main(){
	int T;
	scanf("%d ", &T);
	for (int case_no = 1; case_no <= T; case_no++){
		string line;
		getline(cin, line);
		string sentence;
		for (int i = 0; i < line.size(); i++)
			if (line[i] >= 'a' && line[i] <= 'z')
				sentence += line[i];
		bool magic = false;
		int length = trunc(sqrt(sentence.size()));
		
		if (pow(length, 2) == sentence.size()){
			magic = true;
			
			int x1 = 0, y1 = 0,
				x2 = 0, y2 = 0,
				x3 = length - 1, y3 = length - 1,
				x4 = length - 1, y4 = length - 1;

			for (int i = 0; i < length * length; i++){
				if (!(sentence[get(x1, y1, length)] == sentence[get(x2, y2, length)]
				   && sentence[get(x3, y3, length)] == sentence[get(x4, y4, length)]
			       && sentence[get(x1, y1, length)] == sentence[get(x3, y3, length)])){
					magic = false;
					break;
				}
				else{
					x1++;
					if (x1 == length){
						x1 = 0;
						y1++;
					}
					y2++;
					if (y2 == length){
						y2 = 0;
						x2++;
					}
					x3--;
					if (x3 == -1){
						x3 = length - 1;
						y3--;
					}
					y4--;
					if (y4 == -1){
						y4 = length - 1;
						x4--;
					}
				}
			}
		}
		printf("Case #%d:\n", case_no);
		if (magic)
			printf("%d\n", length);
		else
			printf("No magic :(\n");
	}
	return 0;
}
