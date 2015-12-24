#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int H, M;
	while (scanf("%d:%d", &H, &M) && H){
		double H_angle = (H + (double)M / 60) / 12 * 360,
			   M_angle = (double)M / 60 * 360;
		double angle = abs(H_angle - M_angle);
		if (angle >= 180)
			angle = 360 - angle;
		printf("%.3f\n", angle);
	}
	return 0;
}
