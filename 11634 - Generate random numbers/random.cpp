#include <bits/stdc++.h>

using namespace std;

int next(int a) {
    a = a * a;
    string number = to_string(a);
    while (number.size() < 8)
        number = '0' + number;
    return stoi(number.substr(2, 4));
}

int main() {
    int a;
    while (scanf("%d", &a) && a) {
        int slow = next(a), fast = next(next(a));
        while (slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }

        int lambda = 1;
        slow = next(slow);
        while (slow != fast) {
            slow = next(slow);
            lambda++;
        }

        int mu = 0;
        slow = a;
        while (slow != fast) {
            slow = next(slow);
            fast = next(fast);
            mu++;
        }
        printf("%d\n", mu + lambda);
    }

    return 0;
}
