#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        
        int counter[10] = {0};
        for (int i = 1; i <= N; i++) {
            int temp = i;
            while (temp) {
                int digit = temp % 10;
                temp /= 10;
                counter[digit]++;
            }
        }

        cout << counter[0];
        for (int i = 1; i < 10; i++)
            cout << " " << counter[i];
        cout << "\n";
    }
    return 0;
}
