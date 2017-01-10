#include <bits/stdc++.h>

using namespace std;

int main() {
    long long factorial[21] = {1};
    for (int i = 1; i < 21; i++)
        factorial[i] = factorial[i - 1] * i;

    int n;
    cin >> n;
    for (int cases = 0; cases < n; cases++) {
        string line;
        cin >> line;
        char letter[26] = {0};
        for (char ch : line)
            letter[ch - 'A']++;
        long long solution = factorial[line.size()];
        for (int i = 0; i < 26; i++)
            solution /= factorial[letter[i]];
        printf("Data set %d: %lld\n", cases + 1, solution);
    }
    return 0;
}
