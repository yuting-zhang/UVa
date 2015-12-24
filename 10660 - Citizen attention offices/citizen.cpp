#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <climits>
#include <cstdio>

using namespace std;

struct area_t{
	int row, col, pop;
};

int getDistance(area_t area, int a){
	int row = a / 5, col = a % 5;
	return abs(area.row - row) + abs(area.col - col);
}

int getMin(area_t area, int a, int b, int c, int d, int e){
	int ret = INT_MAX;
	ret = min(ret, getDistance(area, a));
	ret = min(ret, getDistance(area, b));
	ret = min(ret, getDistance(area, c));
	ret = min(ret, getDistance(area, d));
	ret = min(ret, getDistance(area, e));
	return ret * area.pop;
}

int calc(const vector<area_t>& area, int a, int b, int c, int d, int e){
	int ret = 0;
	for (const auto& it : area)
		ret += getMin(it, a, b, c, d, e);
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int n;
		scanf("%d", &n);
		vector<area_t> area(n);
		for (int i = 0; i < n; i++)
			scanf("%d %d %d", &area[i].row, &area[i].col, &area[i].pop);
		int answer[5], curr_min = INT_MAX;
		for (int a = 0; a < 21; a++)
			for (int b = a + 1; b < 22; b++)
				for (int c = b + 1; c < 23; c++)
					for (int d = c + 1; d < 24; d++)
						for (int e = d + 1; e < 25; e++){
							int n_min = calc(area, a, b, c, d, e);
							if (n_min < curr_min){
								curr_min = n_min;
								answer[0] = a;
								answer[1] = b;
								answer[2] = c;
								answer[3] = d;
								answer[4] = e;
							}
						}
		printf("%d %d %d %d %d\n", answer[0], answer[1], answer[2], answer[3], answer[4]);
	}
	return 0;
}
