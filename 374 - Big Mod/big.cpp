#include <bits/stdc++.h>

using namespace std;

long long big_mod(long long B, long long P, long long M) {
    if (P == 0)
        return 1;
    long long result = big_mod(B, P / 2, M);
    if (P % 2 == 0) 
        return result * result % M;
    else 
        return (result * result % M) * B % M;
}

int main(){
    long long B, P, M;
    while (scanf("%lld %lld %lld", &B, &P, &M) == 3) {
        printf("%lld\n", big_mod(B, P, M));
    }
	return 0;
}
