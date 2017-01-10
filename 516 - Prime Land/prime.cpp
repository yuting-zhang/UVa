#include <bits/stdc++.h>

using namespace std;

vector<int> sieve() {
    bitset<35000> bs;
    bs.set();
    bs[0] = bs[1] = false;

    vector<int> primes;

    for (int i = 2; i < 35000; i++) 
        if (bs[i]) {
            for (int j = i * i; j < 35000; j += i) 
                bs[j] = false;
            primes.push_back(i);
        }
    return primes;
}

int main() {
    vector<int> primes = sieve();

    string line;
    while (getline(cin, line) && line != "0") {
        istringstream sin(line);
        int p, e, value = 1;
        while (sin >> p >> e)
            value *= pow(p, e);
        value--;

        map<int, int> counter;

        int index = 0, factor = primes[index];
        while (factor * factor <= value) {
            while (value % factor == 0) {
                value /= factor;
                counter[factor]++;
            }
            factor = primes[++index];
        }
        if (value != 1)
            counter[value]++;
        
        bool first = true;
        for (auto it = counter.rbegin(); it != counter.rend(); it++) {
            if (first)
                first = false;
            else
                printf(" ");
            printf("%d %d", it->first, it->second);
        }
        printf("\n"); 
    }

    return 0;
}
