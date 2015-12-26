#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	unsigned N, L, U;
	while (scanf("%u %u %u", &N, &L, &U) == 3){
		unsigned M = 0;
		for (int i = 31; i >= 0; i--){
			if (!((1 << i) & N))
				if ((M |(1 << i)) <= U)
					M |= (1 << i);
			if (M < L && ((1 << i) & L))
				M |= (1 << i);
		}
		printf("%u\n", M);	
	}
}
