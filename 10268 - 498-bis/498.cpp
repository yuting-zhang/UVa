#include <bits/stdc++.h>

using namespace std;

long long power(int x, int n) {
    if (n < 0)
        return 0;

    long long ret = 1;
    if (n == 0)
        return ret;

    if (n % 2 == 1) {
        ret = power(x, n / 2);
        return ret * ret * x;
    }
    else {
        ret = power(x, n / 2);
        return ret * ret;
    }
}

int main() {
    string line;
    istringstream sin;
    int counter = 0;
    while (getline(cin, line)) {
        counter++;
        vector<int> c;
        int x;
        sin.clear();
        sin.str(line);
        sin >> x;

        getline(cin, line);
        sin.clear();
        sin.str(line);
        int num;
        while (sin >> num)
            c.push_back(num);

        long long sum = 0;
        long long exp = 1;

        for (int j = c.size() - 2; j >= 0; j--) {
            sum += c[j] * (c.size() - j - 1) * exp;
            exp *= x;
        }

        cout << sum << "\n";
    }
    return 0;
}
