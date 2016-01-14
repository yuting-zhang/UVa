#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int N;
int YAdjMat[26][26], MAdjMat[26][26];

void Floyd_Warshall(int (&adjMat)[26][26]){
    for (int k = 0; k < 26; k++)
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}

int main(){
    while (scanf("%d", &N) && N){
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++){
                if (i == j)
                    YAdjMat[i][j] = MAdjMat[i][j] = 0;
                else
                    YAdjMat[i][j] = MAdjMat[i][j] = (1 << 29);
            }
        
        for (int i = 0; i < N; i++){
            char age, dir, x, y;
            int cost;
            scanf(" %c %c %c %c %d", &age, &dir, &x, &y, &cost);
            int (&adjMat)[26][26] = (age == 'Y' ? YAdjMat : MAdjMat);
            adjMat[x - 'A'][y - 'A'] = min(adjMat[x - 'A'][y - 'A'], cost);
            if (dir == 'B')
                adjMat[y - 'A'][x - 'A'] = min(adjMat[y - 'A'][x - 'A'], cost);
        }

        char author, prof;
        scanf(" %c %c ", &author, &prof);

        Floyd_Warshall(YAdjMat);
        Floyd_Warshall(MAdjMat);
        
        int answer = (1 << 29);
        bool place[26];
        memset(place, 0, sizeof place);

        for (int i = 0; i < 26; i++)
            if (YAdjMat[author - 'A'][i] < (1 << 29) && MAdjMat[prof - 'A'][i] < (1 << 29)){
                int energy = YAdjMat[author - 'A'][i] + MAdjMat[prof - 'A'][i];
                if (energy < answer){
                    memset(place, 0, sizeof place);
                    answer = energy;
                    place[i] = true;
                }
                else if (energy == answer)
                    place[i] = true;
            }
        if (answer == (1 << 29))
            printf("You will never meet.\n");
        else{
            printf("%d", answer);
            for (int i = 0; i < 26; i++)
                if (place[i])
                    printf(" %c", (char)(i + 'A'));
            printf("\n");
        }
    }
    return 0;
}
