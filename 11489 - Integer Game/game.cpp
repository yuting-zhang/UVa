#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++) {
        string number;
        cin >> number;
        int sum = 0, multiples = 0;
        for (char digit : number) {
            sum += digit - '0';
            if ((digit - '0') % 3 == 0)
                multiples++;
        }

        bool first_possible = false;
        for (char digit : number) {
            if ((sum - (digit - '0')) % 3 == 0) {
                first_possible = true;
                if ((digit - '0') % 3 == 0)
                    multiples--;
                break;
            }
        }

        cout << "Case " << cases << ": ";
        if (!first_possible)
            cout << "T";
        else if (multiples % 2 == 1)
            cout << "T";
        else
            cout << "S";
        printf("\n");
    }
    return 0;
}
