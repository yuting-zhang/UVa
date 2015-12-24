#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

struct point_t{
    int x, y;
};

bool operator<(const point_t& lhs, const point_t& rhs){
    return lhs.x < rhs.x;
}

using namespace std;

double dist(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2,2));
}

int main(){
    int C;
    scanf("%d", &C);
    for (int i = 0; i < C; ++i){
        int N;
        scanf("%d", &N);
        vector<point_t> points(N);
        for (int j = 0; j < N; ++j)
            scanf("%d %d", &points[j].x, &points[j].y);
        sort(points.begin(), points.end());
        int high = 0;
        double length = 0.0;
        for (int j = points.size() - 2; j >= 0; --j){
            if (points[j].y > high){
                length += ((double)points[j].y - high) / (points[j].y - points[j + 1].y) *
                            dist(points[j].x, points[j].y, points[j + 1].x, points[j + 1].y);
                high = points[j].y;
            }
        }
        printf("%.2f\n", length);
    }
    return 0;
}
