#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

int main(){
	int n, m;
	while (scanf("%d %d\n", &n, &m) && (n || m)){
		bitset<1000050> bitvec;
		bool ok = true;
		while (n--){
			int begin, end;
			scanf("%d %d\n", &begin, &end);
			if (!ok)
				continue;
			for (int i = begin; i < end; i++)
				if (bitvec[i]){
					ok = false;
					break;
				}
				else
					bitvec.set(i);
		}
		while (m--){
			int begin, end, interval;
			scanf("%d %d %d\n", &begin, &end, &interval);
			while (ok && begin <= 1000000){
				for (int i = begin; i < end; i++){
					if (i > 1000000)
						break;
					if (bitvec[i]){
						ok = false;
						break;
					}
					else
						bitvec.set(i);
				}
				begin += interval;
				end += interval;
			}
		}
		if (ok)
			printf("NO CONFLICT\n");
		else
			printf("CONFLICT\n");
	}
	return 0;
}
