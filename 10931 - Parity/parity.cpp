#include <bits/stdc++.h>

using namespace std;

int main() {
    int I;
    while (scanf("%d", &I) && I) {
        int parity = 0;
        string binary;
        while (I) {
            parity += I % 2;
            binary = (I % 2 ? '1' : '0') + binary;
            I >>= 1;
        }

        printf("The parity of %s is %d (mod 2).\n", binary.c_str(), parity);
    }
    return 0;
}
