#include <bits/stdc++.h>

using namespace std;

long long power(int x, int n) {
    long long ret = 1;
    while (n--)
        ret *= x;
    return ret;
}

int main() {
    string line;
    istringstream sin;
    while (getline(cin, line)) {
        sin.clear();
        sin.str(line);
        vector<int> c, x;
        int num;
        while (sin >> num)
            c.push_back(num);

        getline(cin, line);
        sin.clear();
        sin.str(line);
        while (sin >> num)
            x.push_back(num);

        for (int i = 0; i < x.size(); i++) {
            if (i != 0)
                cout << " ";
            long long sum = 0;
            for (int j = 0; j < c.size(); j++)
                sum += c[j] * power(x[i], c.size() - j - 1);
            cout << sum;
        }
        cout << "\n";
    }
    return 0;
}
