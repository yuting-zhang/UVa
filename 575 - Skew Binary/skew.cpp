#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    while (cin >> line && line != "0") {
        long long answer = 0;
        for (int i = line.size() - 1; i >= 0; i--) {
            answer += (line[i] - '0') * ((1 << line.size() - i) - 1);
        }
        cout << answer << "\n";
    }
    return 0;
}
