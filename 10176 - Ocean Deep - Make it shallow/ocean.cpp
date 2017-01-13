#include <bits/stdc++.h>

using namespace std;

#define MOD 131071

vector<long long> power;

long long big_mod(int b, int p) {
    if (p == 0)
        return 1;
    if (power[p])
        return power[p];
    long long result = big_mod(b, p / 2);
    if (p % 2 == 0)
        return power[p] = result * result % MOD;
    else
        return power[p] = (result * result % MOD) * b % MOD;
}

int main(){
    string line, binary;
    while (cin >> line) {
        binary = "";
        while (line.back() != '#') {
            binary += line;
            cin >> line;
        }

        binary += line.substr(0, line.size() - 1);
        
        if (power.size() < binary.size())
            power.resize(binary.size());

        int result = 0;
        for (int i = binary.size() - 1; i >= 0; i--) {
            if (binary[i] == '1')
                result = (result + big_mod(2, binary.size() - 1 - i)) % MOD;
        }
        if (result == 0)
            printf("YES\n");
        else 
            printf("NO\n");
    }
	return 0;
}
