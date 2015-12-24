#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int sz, p;
	int direction[4][2] = {{0,1}, {-1,0},{0,-1},{1,0}};
	while (scanf("%d %d", &sz, &p) && sz){
		int x = sz / 2 + 1, y = sz / 2 + 1,
			heading = 0, count = 0, step = 1, pos = 1;
		while (true){
			if (pos + step >= p){
				x += direction[heading][0] * (p - pos);
				y += direction[heading][1] * (p - pos);
				break;
			}
			x += direction[heading][0] * step;
			y += direction[heading][1] * step;
			count++;
			pos += step;
			if (count == 2){
				step++;
				count = 0;
			}
			
			heading = (heading + 1) % 4;
		}
		printf("Line = %d, column = %d.\n", y, x);
	}
	return 0;
}
