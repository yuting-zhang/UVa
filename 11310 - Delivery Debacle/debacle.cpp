#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<long long> box = {1, 1, 5};
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if (box.size() > n) {
            printf("%lld\n", box[n]);
            continue;
        }

        while (box.size() <= n) {
            box.push_back(box.back() + 4 * box[box.size() - 2] + 2 * box[box.size() - 3]);
        }
        printf("%lld\n", box[n]);
    }
    return 0;
}
