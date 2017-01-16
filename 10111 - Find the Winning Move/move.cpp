#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> board(4, vector<char>(4));
int rows[4], cols[4], diags[2];

// return: 1 'x' wins; -1 'o' wins; 0 draw;
int check_win() {
    int retval = 0;
    for (int i = 0; i < 4; i++) {
        if (rows[i] == 4 || cols[i] == 4)
            return 1;
        if (rows[i] == -4 || cols[i] == -4)
            return -1;
    }
    if (diags[0] == 4 || diags[1] == 4)
        return 1;
    if (diags[0] == -4 || diags[1] == -4)
        return -1;
    return 0;
}

void update(bool x, bool place, int row, int col) {
    if (place)
        board[row][col] = x ? 'x' : 'o';
    else
        board[row][col] = '.';

    int change = x && place || !x && !place ? 1 : -1;
    rows[row] += change;
    cols[col] += change;
    if (row == col)
        diags[0] += change;
    if (row + col == 3)
        diags[1] += change;
}

bool backtrack(bool x, int steps) {
    if (steps == 16)
        return check_win() == 1;

    bool all_win = true;

    for (int row = 0; row < 4; row++)
        for (int col = 0; col < 4; col++)
            if (board[row][col] == '.') {
                update(x, true, row, col);

                int win = check_win();
                if (win == 0)
                    win = backtrack(!x, steps + 1) ? 1 : -1;

                if (win != 1)
                    all_win = false;

                if (!x && win == -1) {
                    update(x, false, row, col);
                    return false;
                }

                if (x && win == 1) {
                    update(x, false, row, col);
                    return true;
                }

                update(x, false, row, col);
            }

    if (!x)
        return all_win;
    else
        return false;
}

int main(){
    char sentinel;
    while (scanf(" %c", &sentinel) && sentinel == '?') {
        memset(rows, 0, sizeof rows);
        memset(cols, 0, sizeof cols);
        memset(diags, 0, sizeof diags);

        int steps = 0;
        for (int row = 0; row < 4; row++)
            for (int col = 0; col < 4; col++) {
                scanf(" %c", &board[row][col]);
                if (board[row][col] != '.') {
                    update(board[row][col] == 'x', true, row, col);
                    steps++;
                }
            }

        pair<int, int> solution = {-1, -1};

        for (int row = 0; row < 4 && solution.first == -1; row++)
            for (int col = 0; col < 4 && solution.first == -1; col++) 
                if (board[row][col] == '.') {
                    update(true, true, row, col);

                    if (check_win() == 1 || backtrack(false, steps + 1)) 
                        solution = {row, col}; 

                    update(true, false, row, col);
                }
        if (solution.first == -1)
            printf("#####\n");
        else
            printf("(%d,%d)\n", solution.first, solution.second);
    }
    return 0;
}
