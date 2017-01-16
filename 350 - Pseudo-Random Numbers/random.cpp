#include <bits/stdc++.h>

using namespace std;

int Z, I, M;

int next(int L) {
    return (Z * L + I) % M;
}

int main(){
    int cases = 0, L;
    while (scanf("%d %d %d %d", &Z, &I, &M, &L) && !(!Z && !I && !M && !L)) {
        int slow = next(L), fast = next(next(L));
        
        while (slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }

        int lambda = 1;
        fast = next(fast);
        while (fast != slow) {
            fast = next(fast);
            lambda++;
        }
        
        printf("Case %d: %d\n", ++cases, lambda);
    }
    return 0;
}
