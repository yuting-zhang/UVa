#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int test_case;
    scanf("%d", &test_case);
    while (test_case--){
        char type;
        int x, y;
        scanf(" %c %d %d", &type, &x, &y);
        if (type == 'r')
            printf("%d\n", min(x, y));
        else if (type == 'k')
            printf("%d\n", (x * y + 1) / 2);
        else if (type == 'K')
            printf("%d\n", ((x + 1) / 2) * ((y + 1) / 2));
        else if (type == 'Q')
            printf("%d\n", min(x, y));
    }
    return 0;
}
