#include <bits/stdc++.h>

using namespace std;

int divisible[12];

bool divisible_by_1(const string &M) {
    if (divisible[0] != -1)
        return divisible[0];

    return divisible[0] = 1;
}

bool divisible_by_2(const string &M) {
    if (divisible[1] != -1)
        return divisible[1];

    return divisible[1] = ((M.back() - '0') % 2 == 0);
}

bool divisible_by_3(const string &M) {
    if (divisible[2] != -1)
        return divisible[2];

    int sum = 0;
    for (char ch : M)
        sum += ch - '0';

    return divisible[2] = (sum % 3 == 0);
}

bool divisible_by_4(const string &M) {
    if (divisible[3] != -1)
        return divisible[3];

    int tail = 0;
    if (M.size() < 3)
        tail = stoi(M);
    else
        tail = stoi(M.substr(M.size() - 2));

    return divisible[3] = (tail % 4 == 0);
}

bool divisible_by_5(const string &M) {
    if (divisible[4] != -1)
        return divisible[4];

    return divisible[4] = (M.back() - '0') % 5 == 0;
}

bool divisible_by_6(const string &M) {
    if (divisible[5] != -1)
        return divisible[5];

    return divisible[5] = divisible_by_2(M) && divisible_by_3(M);
}

bool divisible_by_7(const string &M) {
    if (divisible[6] != -1)
        return divisible[6];

    int index = M.size() - 1, sum = 0;
    bool plus = true;
    while (index - 2 >= 0) {
        if (plus) 
            sum += stoi(M.substr(index - 2, 3));
        else
            sum -= stoi(M.substr(index - 2, 3));
        index -= 3;
        plus = !plus;
    }

    if (index >= 0) {
        if (plus) 
            sum += stoi(M.substr(0, index + 1));
        else
            sum -= stoi(M.substr(0, index + 1));
    }
    return divisible[6] = (sum % 7 == 0);
}

bool divisible_by_8(const string &M) {
    if (divisible[7] != -1)
        return divisible[7];

    int tail;
    if (M.size() < 4)
        tail = stoi(M);
    else
        tail = stoi(M.substr(M.size() - 3));

    return divisible[7] = (tail % 8 == 0);
}

bool divisible_by_9(const string &M) {
    if (divisible[8] != -1)
        return divisible[8];

    int sum = 0;
    for (char ch : M)
        sum += ch - '0';
    return divisible[8] = (sum % 9 == 0);
}

bool divisible_by_10(const string &M) {
    if (divisible[9] != -1)
        return divisible[9];

    return divisible[9] = (M.back() == '0');
}

bool divisible_by_11(const string &M) {
    if (divisible[10] != -1)
        return divisible[10];

    int sum = 0;
    bool plus = true;

    for (char ch : M) {
        if (plus)
            sum += ch - '0';
        else
            sum -= ch - '0';
        plus = !plus;
    }

    return divisible[10] = (sum % 11 == 0);
}

bool divisible_by_12(const string &M) {
    if (divisible[11] != -1)
        return divisible[11];

    return divisible[11] = divisible_by_3(M) && divisible_by_4(M);
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        memset(divisible, -1, sizeof divisible);
        string M;
        cin >> M;
        int S;
        cin >> S;
        bool wonderful = true;
        while (S--) {
            int num;
            cin >> num;
            switch (num) {
            case 1:
                wonderful &= divisible_by_1(M);
                break;
            case 2:
                wonderful &= divisible_by_2(M);
                break;
            case 3:
                wonderful &= divisible_by_3(M);
                break;
            case 4:
                wonderful &= divisible_by_4(M);
                break;
            case 5:
                wonderful &= divisible_by_5(M);
                break;
            case 6:
                wonderful &= divisible_by_6(M);
                break;
            case 7:
                wonderful &= divisible_by_7(M);
                break;
            case 8:
                wonderful &= divisible_by_8(M);
                break;
            case 9:
                wonderful &= divisible_by_9(M);
                break;
            case 10:
                wonderful &= divisible_by_10(M);
                break;
            case 11:
                wonderful &= divisible_by_11(M);
                break;
            case 12:
                wonderful &= divisible_by_12(M);
                break;
            }
        }
        if (wonderful)
            cout << M << " - Wonderful.\n";
        else
            cout << M << " - Simple.\n";
    }
    return 0;
}
