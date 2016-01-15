/* Lazy Correct Program */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

typedef struct {
    int v, a, b;
} Monkey;
#define MAX_MONKEY 128
static Monkey mon[MAX_MONKEY];

int main()
{
    FILE *in, *out;
    
    in = fopen("in", "r");
    out = fopen("out", "r");
    
    
    int N, M, i, j, caseno = 1;
    char buf[64];
    while (fscanf(in, "%d", &N) && N) {
        fscanf(in, "%d", &M);
        for (i = 0; i < N; ++i)
            fscanf(in, "%d %d %d", &mon[i].v, &mon[i].a, &mon[i].b);
        
        printf("Case %d:\n", caseno++);
        fflush(stdout);
        
        fgets(buf, sizeof(buf), out);
        if (buf[strlen(buf)-2] == 'o') {
            printf("You answered \"No\". I can't verify.\n");
        } else {
            int *count = (int*)calloc(sizeof(int), 60000);
            for (i = 0; i < N; ++i) {
                int k, v;
                fscanf(out, "%d", &k);
                v = 0;
                int tmp = mon[i].a - 1;
                while ( k-- ) {
                    int a, b;
                    fscanf(out, " (%d,%d)", &a, &b);
                    assert(a < b);
                    assert(mon[i].a <= a && b <= mon[i].b);
                    assert(tmp < a);
                    tmp = b;
                    v += b-a;
                    for (; a < b; ++a)
                        assert(++count[a] <= M);
                }
                assert(v == mon[i].v);
            }
            free( count );
            fgets(buf, sizeof(buf), out);
            printf("\"Yes\" is yes!!\n");
        }
    }
}
