#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int M, N;
    while (scanf("%d %d", &M, &N) == 2 && (M || N)){
        int knights,
            length = max(M, N),
            width = min(M, N);

        if (width == 0)
            knights = 0;
        else if (width == 1)
            knights = length;
        else if (width == 2){
            knights = (length / 4) * 4;
            if (length % 4 <= 2)
                knights += (length % 4) * 2;
            else
                knights += 4;
        }
        else
            knights = (length * width + 1) / 2;

        printf("%d knights may be placed on a %d row %d column board.\n", knights, M, N);
    }
    return 0;
}
