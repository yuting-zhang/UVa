#include <bits/stdc++.h>

using namespace std;

int from_base4(string num) {
    int ret = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
        switch (num[i]) {
        case 'V':
            break;
        case 'U':
            ret += 1 * (1 << 2 * (num.size() - 1 - i));
            break;
        case 'C':
            ret += 2 * (1 << 2 * (num.size() - 1 - i));
            break;
        case 'D':
            ret += 3 * (1 << 2 * (num.size() - 1 - i));
            break;
        default:
            break;
        }
    }
    return ret;
}

string to_base4(int num) {
    string ret;
    while (num) {
        int rem = num % 4;
        switch (rem) {
        case 0:
            ret = 'V' + ret;
            break;
        case 1:
            ret = 'U' + ret;
            break;
        case 2:
            ret = 'C' + ret;
            break;
        case 3:
            ret = 'D' + ret;
            break;
        default:
            break;
        }
        num /= 4;
    }
    return ret;
}

string sum(string num1, string num2) {
    return to_base4(from_base4(num1) + from_base4(num2));
}

string right(string num) {
    return num.substr(0, num.size() - 1);
}

string left(string num) {
    return num + 'V';
}

int main() {
    int N;
    cin >> N;
    printf("COWCULATIONS OUTPUT\n");
    while (N--) {
        string num1, num2;
        cin >> num1 >> num2;
        for (int i = 0; i < 3; i++) {
            char op;
            cin >> op;
            switch (op) {
            case 'A':
                num2 = sum(num1, num2);
                break;
            case 'R':
                num2 = right(num2);
                break;
            case 'L':
                num2 = left(num2);
                break;
            default:
                break;
            }
        }
        while (num2.size() < 8)
            num2 = 'V' + num2;
        string result;
        cin >> result;
        if (result == num2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    printf("END OF OUTPUT\n");
    return 0;
}
