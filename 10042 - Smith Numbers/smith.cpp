#include <bits/stdc++.h>

using namespace std;

vector<int> get_primes() {
    vector<int> primes;
    vector<bool> sieve(100000, true);
    
    for (int i = 2; i < 100000; i++) {
        if (sieve[i]) {
            primes.push_back(i);
            int j = 2;
            while (i * j < 100000) {
                sieve[i * j] = false;
                j++;
            }
        }
    }
    return primes;
}

int sum_of_digits(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    vector<int> primes = get_primes();
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);

        while (true) {
            N++;
            int sum = sum_of_digits(N);
            int prime_sum = 0;
            
            int temp = N, index = 0;
            int factors = 0;

            while (temp > 1 && primes[index] <= sqrt(temp)) {
                if (temp % primes[index] == 0) {
                    prime_sum += sum_of_digits(primes[index]); 
                    temp /= primes[index]; 
                    factors++;
                }
                else
                    index++;
            }
            if (temp != 1) {
                prime_sum += sum_of_digits(temp);
                factors += 1;
            }

            if (sum == prime_sum && factors > 1) {
                printf("%d\n", N);
                break;
            }
        }
    }
    return 0;
}
