#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct line_t {
    line_t(const pair<int, int> &p1, const pair<int, int> &p2) {
        if (p1.first == p2.first) {
            x1 = x2 = p1.first;
            if (p1.second < p2.second) {
                y1 = p1.second;
                y2 = p2.second;
            }
            else {
                y2 = p1.second;
                y1 = p2.second;
            }
        }
        else {
            y1 = y2 = p1.second;
            if (p1.first < p2.first) {
                x1 = p1.first;
                x2 = p2.first;
            }
            else {
                x2 = p1.first;
                x1 = p2.first;
            }
        }
    }

    int x1, y1, x2, y2;
};

bool operator<(const line_t &lhs, const line_t &rhs) {
    if (lhs.x1 == lhs.x2)
        return lhs.x1 < rhs.x1;
    else
        return lhs.y1 < rhs.y1;
}

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        vector<line_t> vertical, horizontal;
        pair<int, int> first, prev, curr;
        scanf("%d %d", &first.first, &first.second);
        prev = first;
        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d", &curr.first, &curr.second);
            if (curr.first == prev.first)
                vertical.push_back(line_t(curr, prev));
            else
                horizontal.push_back(line_t(curr, prev));
            prev = curr;
        }
        if (curr.first == first.first)
            vertical.push_back(line_t(curr, first));
        else
            horizontal.push_back(line_t(curr, first));

        sort(vertical.begin(), vertical.end());
        sort(horizontal.begin(), horizontal.end());
       
        int x, y;
        scanf("%d %d", &x, &y);

        bool in_vertical = false, in_horizontal = false;
        for (const auto &line : vertical) {
            if (x < line.x1)
                break;
            if (y >= line.y1 && y <= line.y2)
                in_vertical = !in_vertical;
        }

        for (const auto &line : horizontal) {
            if (y < line.y1)
                break;
            if (x >= line.x1 && x <= line.x2)
                in_horizontal = !in_horizontal;
        }

        printf("%c\n", in_vertical && in_horizontal ? 'T' : 'F');
    }
    return 0; 
}
