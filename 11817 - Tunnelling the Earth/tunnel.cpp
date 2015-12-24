#include <iostream>
#include <cstdio>
#include <cmath>

#define PI acos(0) * 2
#define RADIUS 6371009

using namespace std;

double toRad(double a){
	return a / 360 * 2 * PI;
}

double getPhi(double a){
	if (a >= 0)
		return toRad(90 - a);
	else
		return toRad(abs(a) + 90);
}

double getTheta(double a){
	if (a >= 0)
		return toRad(a);
	else 
		return toRad(360 - abs(a));
}

int main(){
	int N;
	scanf("%d", &N);
	while (N--){
		double a, b, c, d;
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		double phi1 = getPhi(a), theta1 = getTheta(b),
			   phi2 = getPhi(c), theta2 = getTheta(d);

		double x1 = RADIUS * sin(phi1) * cos(theta1),
			   y1 = RADIUS * sin(phi1) * sin(theta1),
			   z1 = RADIUS * cos(phi1);
		double x2 = RADIUS * sin(phi2) * cos(theta2),
			   y2 = RADIUS * sin(phi2) * sin(theta2),
			   z2 = RADIUS * cos(phi2);
		double directLine = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
		double angle = acos((x1 * x2 + y1 * y2 + z1 * z2) / (sqrt(pow(x1, 2) + pow(y1, 2) + pow(z1, 2))) /
															(sqrt(pow(x2, 2) + pow(y2, 2) + pow(z2, 2))));
		double circle = 2 * PI * RADIUS * angle / (2 * PI);
		printf("%.0f\n", abs(circle - directLine));
	}
	return 0;
}
