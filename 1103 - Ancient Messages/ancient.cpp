#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int H, W;
vector<vector<bool>> image;
vector<vector<int>> color;

void loadImage(){
    image.assign(H, vector<bool>(W * 4, false));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++){
            char ch;
            scanf(" %c ", &ch);
            int num;
            if (ch >= '0' && ch <= '9')
                num = ch - '0';
            else
                num = 10 + ch - 'a';
            for (int k = 0; k < 4; k++)
                image[i][(j + 1) * 4 - 1 - k] = (num & (1 << k));    
        }
    W *= 4;
}

int walk[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void blackDFS(int row, int col, int coloring){
    color[row][col] = coloring;
    for (int i = 0; i < 4; i++){
        int r = row + walk[i][0], c = col + walk[i][1];
        if (r >= 0 && r < H && c >= 0 && c < W && image[r][c] && color[r][c] == -1)
            blackDFS(r, c, coloring);
    }
}

int whiteDFS(int row, int col){
    color[row][col] = 0;
    bool global = false;
    int ret = -1;
    for (int i = 0; i < 4; i++){
        int r = row + walk[i][0], c = col + walk[i][1];
        if (r < 0 || r >= H || c < 0 || c >= W)
            global = true;
        else if (color[r][c] > 0){
            if (ret == -1)
                ret = color[r][c];
            else
                global = global || !(ret == color[r][c]);
        } 
        else if (color[r][c] == -1){
            int result = whiteDFS(r, c);
            if (result == 0)
                global = true;
            else if (ret == -1)
                ret = result;
            else if (result != -1)
                global = global || !(ret == result);
        }
    }

    if (global)
        return 0;
    else 
        return ret;
}

int main(){
    int test_case = 0;
    while (scanf("%d %d", &H, &W) && H && W){
        test_case++;
        loadImage();
        color.assign(H, vector<int>(W, -1));
        int glyph = 0;
        for (int row = 0; row < H; row++)
            for (int col = 0; col < W; col++)
                if (image[row][col] && color[row][col] == -1){
                    glyph++;
                    blackDFS(row, col, glyph);
                }

        vector<int> whiteCount(glyph, 0);
        for (int row = 0; row < H; row++)
            for (int col = 0; col < W; col++)
                if (!image[row][col] && color[row][col] == -1){
                    int result = whiteDFS(row, col);
                    if (result > 0)
                        whiteCount[result - 1]++;
                }

        string answer;
        for (int i = 0; i < glyph; i++){
            switch (whiteCount[i]){
            case 0:
                answer += 'W';
                break;
            case 1:
                answer += 'A';
                break;
            case 2:
                answer += 'K';
                break;
            case 3:
                answer += 'J';
                break;
            case 4:
                answer += 'S';
                break;
            case 5:
                answer += 'D';
                break;
            }
        }

        sort(answer.begin(), answer.end());
        cout << "Case " << test_case << ": " << answer << "\n";
    }
    return 0;
}
