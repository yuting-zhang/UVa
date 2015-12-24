#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int DPS(const vector<vector<char>>& world, vector<vector<bool>>& visited,
        int row, int column, int king_row, int king_column, bool& king_territory, char land)
{
    const int direction[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    visited[row][column] = true;
    if (world[row][column] != land)
        return 0;
    if (row == king_row && column == king_column)
        king_territory = true;

    int land_size = 1;

    for (int i = 0; i < 4; ++i){
        int new_row = row + direction[i][0], new_column = column + direction[i][1];
        if (new_column == -1)
            new_column = world[0].size() - 1;
        if (new_column == world[0].size())
            new_column = 0;

        if (new_row >= 0 && new_row < world.size() && !visited[new_row][new_column])
                land_size += DPS(world, visited, new_row, new_column,
                                 king_row, king_column, king_territory, land);
    }
    if (king_territory)
        return 0;
    else
        return land_size;
}


int main(){
    //ifstream fin("continents.in");
    istream& in(cin);

    while (in){
        int M, N;
        in >> M >> N;
        if (!in)
            break;
        vector<vector<char>> world(M, vector<char>(N));
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                in >> world[i][j];
        int king_row, king_column;
        in >> king_row>> king_column;
        char land = world[king_row][king_column];

        vector<vector<bool>> visited(M, vector<bool>(N, false));
        int max_land = 0;
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j){
                if (visited[i][j])
                    continue;
                bool king_territory = false;
                int new_land = DPS(world, visited, i, j, king_row, king_column, king_territory, land);
                if (new_land > max_land)
                    max_land = new_land;
            }
        cout << max_land << "\n";
    }
}
