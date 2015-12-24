#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct state_t
{
    int row, column;
    int orientation;// north 0 east 1 south 2 west 3
    int time;
};

bool operator==(const state_t& lhs, const state_t& rhs)
{
    return lhs.row == rhs.row && lhs.column == rhs.column;
}

int main()
{
    ifstream fin("robot.in");
    istream& in(cin);

    while (in)
    {
        int M, N;
        in >> M >> N;
        if (M == 0 && N == 0)
            break;
        vector<vector<bool>> obstacle(M, vector<bool>(N, false));

        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
            {
                int input;
                in >> input;
                obstacle[i][j] = input ? true : false;
            }


        state_t start_state, end_state;
        in >> start_state.row >> start_state.column >> end_state.row >> end_state.column;
        string facing;
        in >> facing;

        --start_state.row;
        --start_state.column;
        --end_state.row;
        --end_state.column;

        if (facing == "north")
            start_state.orientation = 0;
        else if (facing == "east")
            start_state.orientation = 1;
        else if (facing == "south")
            start_state.orientation = 2;
        else
            start_state.orientation = 3;

        start_state.time = 0;

        if (start_state == end_state)
        {
            cout << "0\n";
            continue;
        }

        bool found = false;
        queue<state_t> Queue;
        vector<vector<vector<bool>>> visited(M, vector<vector<bool>>(N, vector<bool>(4, false)));
        Queue.push(start_state);
        visited[start_state.row][start_state.column][start_state.orientation] = true;

        int direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
        while (!Queue.empty())
        {
            state_t curr_state = Queue.front();
            Queue.pop();
            for (int i = 1; i <= 3; ++i)
            {
                bool has_obstacle = false;
                int row = curr_state.row, column = curr_state.column;
                for (int j = 1; j <= i; ++j)
                {
                    row += direction[curr_state.orientation][0];
                    column += direction[curr_state.orientation][1];
                    if (row < 0 || row + 1 >= M || column < 0 || column + 1>= N)
                    {
                        has_obstacle =true;
                        break;
                    }
                    if (obstacle[row][column] || obstacle[row + 1][column] ||
                        obstacle[row][column + 1] || obstacle[row + 1][column + 1])
                    {
                        has_obstacle = true;
                        break;
                    }
                }
                if (!has_obstacle && !visited[row][column][curr_state.orientation])
                {
                    state_t n_state;
                    n_state.row = row;
                    n_state.column = column;
                    n_state.orientation = curr_state.orientation;
                    n_state.time = curr_state.time + 1;
                    if (n_state == end_state)
                    {
                        found = true;
                        cout << n_state.time << "\n";
                        break;
                    }
                    else
                    {
                        Queue.push(n_state);
                        visited[row][column][n_state.orientation] = true;
                    }

                }
            }
            if (found)
                break;
            state_t n_state = curr_state;
            n_state.time += 1;

            int n_orientation = curr_state.orientation + 1;
            if (n_orientation == 4)
                n_orientation = 0;
            n_state.orientation = n_orientation;
            if (!visited[n_state.row][n_state.column][n_state.orientation])
            {
                Queue.push(n_state);
                visited[n_state.row][n_state.column][n_state.orientation] = true;
            }

            n_orientation = curr_state.orientation - 1;
            if (n_orientation == -1)
                n_orientation = 3;
            n_state.orientation = n_orientation;
            if (!visited[n_state.row][n_state.column][n_state.orientation])
            {
                Queue.push(n_state);
                visited[n_state.row][n_state.column][n_state.orientation] = true;
            }
        }
        if (!found)
            cout << "-1\n";
    }
}
