#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int N, M, S;
char arena[105][105];
int walk[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
int r, c, face;

void loadArena(){
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++){
            scanf(" %c ", &arena[i][j]);
            if (arena[i][j] == 'N' || arena[i][j] == 'S' || 
                arena[i][j] == 'L' || arena[i][j] == 'O'){
                switch (arena[i][j]){
                case 'N':
                    face = 0;
                    break;
                case 'S':
                    face = 2;
                    break;
                case 'L':
                    face = 1;
                    break;
                case 'O':
                    face = 3;
                    break;
                }
                r = i;
                c = j;
            } 
        }
}
    
int main(){
    while (scanf("%d %d %d", &N, &M, &S) && N){
        loadArena();
        int collect = 0;
        char ch;
        for (int i = 0; i < S; i++){
            scanf(" %c ", &ch);
            switch (ch){
            case 'D':
                face = (face + 1) % 4;
                break;
            case 'E':
                face = (face + 3) % 4;
                break;
            case 'F':
                int new_r = r + walk[face][1], new_c = c + walk[face][0];
                if (new_r >= 0 && new_r < N && new_c >= 0 && new_c < M && arena[new_r][new_c] != '#'){
                    r = new_r;
                    c = new_c;
                    if (arena[r][c] == '*'){
                        collect++;
                        arena[r][c] = '.';
                    }
                }
                break;
            }
        } 
        printf("%d\n", collect);
        
    }
}
