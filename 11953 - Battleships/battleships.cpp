#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool DPS(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c)
{
    if (visited[r][c])
        return false;
    const int direction[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
    visited[r][c] = true;
    if (grid[r][c] == '.')
        return false;

    bool sank = true;
    if (grid[r][c] == 'x')
        sank = false;

    for (int i = 0; i < 4; ++i)
    {
        int n_r = r + direction[i][0], n_c = c + direction[i][1];
        if (n_r >= 0 && n_r < grid.size() && n_c >= 0 && n_c < grid.size())
        {
            if (!visited[n_r][n_c])
                if (DPS(grid, visited, n_r, n_c))
                    sank = false;
        }
    }

    return !sank;
}

int main()
{
    //ifstream fin("battleships.in");
    istream& in(cin);
    int T;
    in >> T;
    for (int i = 0; i < T; ++i)
    {
        int N;
        in >> N;
        vector<vector<char>> grid(N, vector<char>(N));
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                in >> grid[j][k];
        int alive = 0;
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                if (DPS(grid,visited, j, k))
                    ++alive;
        cout << "Case " << i + 1<< ": " << alive<< "\n";
    }

    return 0;
}
