#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1)

pair<double, double> get_pos(int n) {
    int level = sqrt(n);
    int remain = n - level * level + 1;
    double x = -(level + 1) * 0.5 + remain * 0.5;
    double height = cos(PI / 6);
    double sub_height = 0.5 * tan(PI / 6);
    double y = level * height;
    if (remain % 2 == 1)
        y += (height - sub_height);
    else
        y += sub_height;
    return make_pair(x, y);
}

double dist(const pair<double, double> &p1, const pair<double, double> &p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
    long long n, m;
    while (scanf("%lld %lld", &n, &m) == 2) {
        auto pos1 = get_pos(n);
        auto pos2 = get_pos(m);
        printf("%.3f\n", dist(pos1, pos2));
    }
    return 0;
}
