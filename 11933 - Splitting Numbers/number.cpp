#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	unsigned n;
	while (scanf("%d", &n) && n){
		int count = 0;
		unsigned a = 0, b = 0;
		for (int i = 0; i < 32; i++)
			if ((1 << i) & n){
				count++;
				if (count % 2)
					a |= (1 << i);
				else
					b |= (1 << i);
			}
		printf("%d %d\n", a, b);
	}
	return 0;
}
