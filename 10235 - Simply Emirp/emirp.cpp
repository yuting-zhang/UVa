#include <bits/stdc++.h>

using namespace std;

vector<int> get_primes() {
    vector<int> primes;
    vector<bool> sieve(1000000, true);

    for (int i = 2; i < 1000000; i++) {
        if (sieve[i]) {
            primes.push_back(i);
            int j = i * 2;
            while (j < 1000000) {
                sieve[j] = false;
                j += i;
            }
        }
    }
    return primes;
}

int main() {
    vector<int> primes = get_primes();
    string line;
    while (getline(cin, line)) {
        int num1 = stoi(line);
        reverse(line.begin(), line.end());
        int num2 = stoi(line);
        if (binary_search(primes.begin(), primes.end(), num1)) {
            if (num2 != num1 && 
                binary_search(primes.begin(), primes.end(), num2))
                printf("%d is emirp.\n", num1);
            else
                printf("%d is prime.\n", num1);
        }
        else
            printf("%d is not prime.\n", num1);
    }
    return 0;
}
