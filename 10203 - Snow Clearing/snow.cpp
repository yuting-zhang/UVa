#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    string line;
    getline(cin, line);
    T = stoi(line);

    getline(cin, line);
    bool first = true;
    while (T--) {
        if (first)
            first = false;
        else
            cout << "\n";

        getline(cin, line);
        istringstream sin(line);
        int x1, y1, x2, y2;
        sin >> x1 >> y1;

        double total = 0;
        while (getline(cin, line) && !line.empty()) {
            sin.str(line);
            sin.clear();
            sin >> x1 >> y1 >> x2 >> y2;
            total += pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5) / 1000
                    / 20 * 2;
        }
        int hour = total;

        int minute = round((total - hour) * 60);
        if (minute == 60) {
            hour++;
            minute = 0;
        }

        cout << hour << ":";
        if (minute < 10)
            cout << "0";
        cout << minute << "\n";
    }
    return 0;
}
