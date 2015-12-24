#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double evaluate(int p, int q, int r, int s, int t, int u, double x){
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double binary_search(int p, int q, int r, int s, int t, int u, double left, double right){
	double mid = (left + right) / 2;
	double result = evaluate(p, q, r, s, t, u, mid);
	if (abs(result) < 0.000001)
		return mid;
	if (result > 0)
		return binary_search(p, q, r, s, t, u, mid, right);
	else
		return binary_search(p, q, r, s, t, u, left, mid);
}

int main(){
	int p, q, r, s, t, u;
	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6){
		if (evaluate(p, q, r, s, t, u, 0) < 0 || evaluate(p, q, r, s, t, u, 1) > 0)
			printf("No solution\n");
		else{
			printf("%.4f\n", binary_search(p, q, r, s, t, u, 0, 1));
		}
	}
	return 0;
}
