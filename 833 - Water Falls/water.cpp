#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

struct line{
	line(int x1, int y1, int x2, int y2, int minx, int maxx):
		x1(x1), y1(y1), x2(x2), y2(y2), minx(minx), maxx(maxx){}
	int x1, y1, x2, y2;
	int minx, maxx;
	double a, b;
};

int main(){
	int TC;
	bool first = true;
	scanf("%d", &TC);
	while (TC--){
		if (first)
			first = false;
		else
		 	printf("\n");
		int P;
		scanf("%d", &P);
		vector<line> lines;
		lines.reserve(P);
		for (int i = 0; i < P; i++){
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			if (x1 == x2)
				continue;
			if (y1 > y2){
				swap(x1, x2);
				swap(y1, y2);
			}
			
			line new_line(x1, y1, x2, y2, min(x1, x2), max(x1, x2));
			new_line.a = ((double)(y2) - y1) / (x2 - x1);
			new_line.b = y1 - new_line.a * x1;
			lines.push_back(new_line);
		}

		int S;
		scanf("%d", &S);
		while (S--){
			int x, y;
			scanf("%d %d", &x, &y);
			int idx;
			while (true){
				bool fall = false;
				double new_y = 0;
				for (int i = 0; i < lines.size(); i++){
					if (lines[i].y1 <= y && lines[i].minx < x && lines[i].maxx > x){
						double curr_y = lines[i].a * x + lines[i].b;
						if (curr_y < y && curr_y > new_y){
							new_y = curr_y;
							idx = i;
							fall = true;
						}
					}
				}
				if (!fall)
					break;
				else{
					x = lines[idx].x1;
					y = lines[idx].y1;
				}
			}	
			printf("%d\n", x);
		}

	}
}
