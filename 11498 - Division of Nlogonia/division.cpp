#include <iostream>

using namespace std;

int main()
{
    int K;
    while (scanf("%d", &K) && K)
    {
        int N, M;
        scanf("%d %d", &N, &M);
        while (K--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            if (x == N || y == M)
                printf("divisa\n");
            else if (x < N && y > M)
                printf("NO\n");
            else if (x > N && y > M)
                printf("NE\n");
            else if (x < N && y < M)
                printf("SO\n");
            else
                printf("SE\n");
        }
    }
    return 0;
}
