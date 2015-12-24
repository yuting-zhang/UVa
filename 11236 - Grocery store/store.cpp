#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	for (int i = 1; i < 212; i++)
		for (int j = i; j <= 2000; j++){
			if ((long long)i * j * j * j > 2000000000 || i + j + j + j > 2000)
				break;
			for (int k = j; k <= 2000; k++){
				if ((long long)i * j * k * k > 2000000000 || i + j + k + k > 2000)
					break;

				int temp = i * j * k - 1000000;
				if (temp == 0)
					continue;	
				int l = 1000000 * (i + j + k) / temp;

				if (l < k || i * j * k * l > 2000000000 || i + j + k + l > 2000)
					continue;
				if ((long long)i * j * k * l == ((long long)i + j + k + l) * 1000000)
					printf("%d.%0.2d %d.%0.2d %d.%0.2d %d.%0.2d\n", i / 100, i % 100,
					       j / 100, j % 100,  k / 100, k % 100, l / 100, l % 100);
			}
		}
	return 0;
}
