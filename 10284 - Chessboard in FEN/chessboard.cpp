#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void go_attack(int i, int j, int di, int dj, char board[8][8], bool safe[8][8]){
    i += di;
    j += dj;
    if (i < 8 && i >= 0 && j < 8 && j >= 0)
        if (board[i][j] != ' ')
            return;
        else{
            safe[i][j] = false;
            go_attack(i, j, di, dj, board, safe);
        }
}

void valid_attack(int i, int j, bool safe[][8]){
    if (i < 8 && i >= 0 && j < 8 && j >= 0)
        safe[i][j] = false;
}

int main(){
    string line;
    while (getline(cin, line)){
        char board[8][8];
        int row = 0, column = 0;
        for (int i = 0; i < line.size(); ++i){
            if (line[i] == '/')
                ++row, column = 0;
            else if (line[i] >= '1' && line[i] <= '9'){
                for (int j = 0; j < line[i] - '0'; ++j)
                    board[row][column++] = ' ';
            }
            else
                board[row][column++] = line[i];
        }

        bool safe[8][8];
        memset(safe, true, sizeof(safe));

        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j){
                if (board[i][j] == ' ')
                    continue;
                safe[i][j] = false;

                if (board[i][j] == 'p'){
                    valid_attack(i + 1, j - 1, safe);
                    valid_attack(i + 1, j + 1, safe);
                }
                else if (board[i][j] == 'P'){
                    valid_attack(i - 1, j - 1, safe);
                    valid_attack(i - 1, j + 1, safe);
                }
                else if (board[i][j] == 'k' || board[i][j] == 'K'){
                    valid_attack(i - 1, j - 1, safe);
                    valid_attack(i - 1, j, safe);
                    valid_attack(i - 1, j + 1, safe);
                    valid_attack(i, j - 1, safe);
                    valid_attack(i, j + 1, safe);
                    valid_attack(i + 1, j - 1, safe);
                    valid_attack(i + 1, j, safe);
                    valid_attack(i + 1, j + 1, safe);
                }
                else if (board[i][j] == 'n' || board[i][j] == 'N'){
                    valid_attack(i - 1, j - 2, safe);
                    valid_attack(i - 2, j - 1, safe);
                    valid_attack(i - 2, j + 1, safe);
                    valid_attack(i - 1, j + 2, safe);
                    valid_attack(i + 1, j - 2, safe);
                    valid_attack(i + 2, j - 1, safe);
                    valid_attack(i + 2, j + 1, safe);
                    valid_attack(i + 1, j + 2, safe);
                }
                else if (board[i][j] == 'r' || board[i][j] == 'R'){
                    go_attack(i, j, -1, 0, board, safe);
                    go_attack(i, j, 1, 0, board, safe);
                    go_attack(i, j, 0, 1, board, safe);
                    go_attack(i, j, 0, -1, board, safe);
                }
                else if (board[i][j] == 'B' || board[i][j] == 'b'){
                    go_attack(i, j, -1, -1, board, safe);
                    go_attack(i, j, -1, 1, board, safe);
                    go_attack(i, j, 1, -1, board, safe);
                    go_attack(i, j, 1, 1, board, safe);
                }
                else {
                    go_attack(i, j, -1, 0, board, safe);
                    go_attack(i, j, 1, 0, board, safe);
                    go_attack(i, j, 0, 1, board, safe);
                    go_attack(i, j, 0, -1, board, safe);
                    go_attack(i, j, -1, -1, board, safe);
                    go_attack(i, j, -1, 1, board, safe);
                    go_attack(i, j, 1, -1, board, safe);
                    go_attack(i, j, 1, 1, board, safe);
                }

            }
        int count = 0;
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                if (safe[i][j])
                    count++;

        printf("%d\n", count);
    }
    return 0;
}
