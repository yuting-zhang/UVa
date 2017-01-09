#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int num;
    while (scanf("%d", &num) && num) {
        vector<int> s;
        s.push_back(num);
        while (scanf("%d", &num) && num)
            s.push_back(num);
        for (int i = 1; i < s.size(); i++)
            s[i] -= s[0];
        int answer = abs(s[1]);
        for (int i = 1; i < s.size() - 1; i++) {
            if (answer > s[i + 1])
                answer = gcd(answer, abs(s[i + 1]));
            else
                answer = gcd(abs(s[i + 1]), answer);
        }
        
        printf("%d\n", answer);
    }
    return 0;
}
