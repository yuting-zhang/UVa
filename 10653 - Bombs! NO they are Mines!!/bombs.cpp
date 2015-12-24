#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

// structs are for fun
struct point_t
{
    int r, c;
};

bool operator==(const point_t& lhs, const point_t& rhs)
{
    return lhs.r == rhs.r && lhs.c == rhs.c;
}

struct state_t
{
    point_t pos;
    int step;
};

int BFS(point_t start_point, point_t end_point, const vector<vector<bool>>& mines)
{
    const int direction[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int R = mines.size(), C = mines[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    queue<state_t> Queue;
    Queue.push({start_point, 0});
    visited[start_point.r][start_point.c] = true;

    while (!Queue.empty())
    {
        state_t state = Queue.front();
        Queue.pop();

        for (int i = 0; i < 4; ++i)
        {
            point_t new_pos = {state.pos.r + direction[i][0], state.pos.c + direction[i][1]};

            // end_point check
            if (new_pos == end_point)
                return state.step + 1;

            // boundary check
            if (new_pos.r >= 0 && new_pos.r < R && new_pos.c >= 0 && new_pos.c < C)
                if (!visited[new_pos.r][new_pos.c] && !mines[new_pos.r][new_pos.c])
                {
                    visited[new_pos.r][new_pos.c] = true;
                    Queue.push({new_pos, state.step + 1});
                }
        }
    }
}

void process(istream& in)
{
    while (in)
    {
        int R, C, rows;
        in >> R >> C;

        // end of test cases
        if (R == 0 && C == 0)
            break;

        in >> rows;
        vector<vector<bool>> mines(R, vector<bool>(C, false));
        for (int i = 0; i < rows; ++i)
        {
            int row_number, number_of_mines;
            in >> row_number >> number_of_mines;
            for (int j = 0; j < number_of_mines; ++j)
            {
                int column_number;
                in >> column_number;
                mines[row_number][column_number] = true;
            }
        }
        point_t start_point, end_point;
        in >> start_point.r >> start_point.c >> end_point.r >> end_point.c;
        cout << BFS(start_point, end_point, mines)<< "\n";
    }
}

int main()
{
    //ifstream fin("bombs.in");
    process(cin);
    return 0;
}
