#include <bits/stdc++.h>

using namespace std;

const char* get_suffix(int n) {
    if (n % 100 >= 11 && n % 100 <= 13)
        return "th";
    if (n % 10 == 1)
        return "st";
    if (n % 10 == 2)
        return "nd";
    if (n % 10 == 3)
        return "rd";
    return "th";
}

int main() {
    vector<long long> humble(5842);
    humble[0] = 1;
    int two = 0, three = 0, five = 0, seven = 0;

    for (int i = 1; i < 5842; i++) {
        int entry = min(min(humble[two] * 2, humble[three] * 3),
                        min(humble[five] * 5, humble[seven] * 7));
        humble[i] = entry;
        if (entry == humble[two] * 2)
            two++;
        if (entry == humble[three] * 3)
            three++;
        if (entry == humble[five] * 5)
            five++;
        if (entry == humble[seven] * 7)
            seven++;
    }

    int n;
    while (scanf("%d", &n) && n) {
        printf("The %d%s humble number is %lld.\n", n, get_suffix(n), 
             humble[n - 1]);
    }
    return 0;
}
