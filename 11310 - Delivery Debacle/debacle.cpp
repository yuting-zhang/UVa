#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<long long> box = {1, 1};
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
            box.push_back(box.back() + 4 * box[box.size() - 2]);
        }
        printf("%lld\n", box[n]);
    }
    return 0;
}
