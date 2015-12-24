#include <iostream>
#include <cmath>
#include <cstdio>
#include <utility>

using namespace std;

pair<double, double> makeLine(double x1, double y1, double x2, double y2){
	double a, b;
	a = (y1 - y2) / (x1 - x2);
	b = y1 - x1 * a;
	return make_pair(a, b);
}

int main(){
	printf("INTERSECTING LINES OUTPUT\n");
	int N;
	scanf("%d", &N);
	while (N--){
		double x1, y1, x2, y2, x3, y3, x4, y4;
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		
		if (x1 == x2 || x3 == x4){
			if (x1 == x2 && x3 == x4){
				if (x1 == x3)
					printf("LINE\n");
				else
					printf("NONE\n");
			}
			else if (x1 == x2){
				auto line = makeLine(x3, y3, x4, y4);
				double y = line.first * x1 + line.second;
				printf("POINT %.2f %.2f\n", x1, y);
			}
			else if (x3 == x4){
				auto line = makeLine(x1, y1, x2, y2);
				double y = line.first * x3 + line.second;
				printf("POINT %.2f %.2f\n", x3, y);
			}
		}
		else{
			pair<double, double> line1 = makeLine(x1, y1, x2, y2), line2 = makeLine(x3, y3, x4, y4);	
			if (line1 == line2)
				printf("LINE\n");
			else if (line1.first == line2.first)
				printf("NONE\n");
			else{

				double x = (line2.second - line1.second) / (line1.first - line2.first);
				double y = line1.first * x + line1.second;
				printf("POINT %.2f %.2f\n", x, y);
			}
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
