#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main(){
	int n;
	while (scanf("%d", &n) && n){
		multiset<long long> bills;
		long long total = 0;
		for (int i = 0; i < n; i++){
			int k;
			scanf("%d", &k);
			for (int j = 0; j < k; j++){
				long long bill;
				scanf("%d", &bill);
				bills.insert(bill);
			}
			long long lo = *bills.begin(),
				hi = *(--bills.end());
			bills.erase(bills.begin());
			bills.erase(--bills.end());
			total += hi - lo;	
		}
		printf("%lld\n", total);
	}
	return 0;
}
