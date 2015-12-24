#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        if (i)
            printf("\n");
        int a_x1, a_x2, a_y1, a_y2, b_x1, b_x2, b_y1, b_y2;
        scanf("%d %d %d %d %d %d %d %d", &a_x1, &a_y1, &a_x2, &a_y2, &b_x1, &b_y1, &b_x2, &b_y2);
        if (a_x1 >= b_x2 || b_x1 >= a_x2 || a_y1 >= b_y2 || b_y1 >= a_y2){
            printf("No Overlap\n");
            continue;
        }

        int x1, x2, y1, y2;
        x1 = max(a_x1, b_x1);
        x2 = min(a_x2, b_x2);
        y1 = max(a_y1, b_y1);
        y2 = min(a_y2, b_y2);

        printf("%d %d %d %d\n", x1, y1, x2, y2);
    }
    return 0;
}
