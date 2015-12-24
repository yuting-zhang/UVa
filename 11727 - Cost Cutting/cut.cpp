#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k)
    {
        int salary[3];
        scanf("%d %d %d", &salary[0], &salary[1], &salary[2]);
        for (int i = 0; i < 2; ++i)
            for (int j = i + 1; j < 3; ++j)
                if (salary[i] > salary[j])
                {
                    int temp = salary[i];
                    salary[i] = salary[j];
                    salary[j] = temp;
                }
        printf("Case %d: %d\n", k, salary[1]);
    }
    return 0;
}
