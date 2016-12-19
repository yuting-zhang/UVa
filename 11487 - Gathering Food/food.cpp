#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<vector<int>>>> vvvvi;
typedef pair<int, int> ii;

int shortest_path(const vector<vector<char>> &grid, char last,
                  int start_row, int start_col) {

    if (last == 'A')
        return 0;

    // first pair is current row and current col
    // second integer is the current length
    queue<pair<ii, int>> q;
    vvi visited(grid.size(), vi(grid.size(), 0));

    int answer = 0;
    char food = 'B';
    visited[start_row][start_col] = 1;

    q.push({{start_row, start_col}, 0});

    const int walk[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool done = false;

    while (!q.empty() && !done) {
        auto front = q.front();
        q.pop();
        int row = front.first.first;
        int col = front.first.second;
        int len = front.second;

        for (int k = 0; k < 4; k++) {
            int new_row = row + walk[k][0];
            int new_col = col + walk[k][1];
            if (new_row >= 0 && new_col >= 0 && 
                new_row < grid.size() && new_col < grid.size() &&
                !visited[new_row][new_col]) {

                visited[new_row][new_col] = 1;
                if (grid[new_row][new_col] == '#' ||
                    (isalpha(grid[new_row][new_col]) &&
                    grid[new_row][new_col] > food))
                    continue;

                if (grid[new_row][new_col] == food) {
                    answer += len + 1;
                    
                    if (food == last) {
                        done = true;
                        break;
                    }

                    food++;

                    while (!q.empty())
                        q.pop();

                    visited.assign(grid.size(), vi(grid.size(), 0));
                    visited[new_row][new_col] = 1;

                    q.push({{new_row, new_col}, 0}); 
                    break;
                }

                q.push({{new_row, new_col}, len + 1}); 
            }
        }
    }

    return done ? answer : -1;
}

int solve(int row, int col, char food, int length, 
          const vector<vector<char>> &grid, vvvvi &memo) {
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid.size())
        return 0;
    
    if (length < 0)
        return 0;

    if (grid[row][col] == '#')
        return 0;

    if (isalpha(grid[row][col]) && grid[row][col] > food)
        return 0;

    int &local = memo[row][col][food - 'A'][length];
    if (local != -1)
        return local;

    local = 0;

    if (grid[row][col] == food) {
        if (food == 'A') {
            local = 1;
            return local;
        }

        food -= 1;
    }
    
    const int walk[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < 4; i++) {
        int new_row = row + walk[i][0];
        int new_col = col + walk[i][1];
        int result = solve(new_row, new_col, food, length - 1, grid, memo);    
        local = (local + result) % 20437;
    }

    return local;
}

int main() {
    int N, test_case = 0;

    while (cin >> N && N) {
        vector<vector<char>> grid(N, vector<char>(N));
        int last = 'A';
        int start_row, start_col;
        int stop_row = -1, stop_col;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'A') {
                    start_row = i;
                    start_col = j;
                    if (stop_row == -1) {
                        stop_row = i;
                        stop_col = j;
                    }
                }

                if (isalpha(grid[i][j]) && grid[i][j] > last) {
                    last = grid[i][j];
                    stop_row = i;
                    stop_col = j;
                }
            }

        int length = shortest_path(grid, last, start_row, start_col);
        
        cout << "Case " << ++test_case << ": ";
        if (length == -1) {
            cout << "Impossible\n";
            continue;
        }

        // 1st dimension row
        // 2nd dimension column
        // 3rd dimension current alphabet
        // 4th dimension current length
        vvvvi memo(N, vvvi(N, vvi(last - 'A' + 1, vi(length + 1, -1))));

        int solution = solve(stop_row, stop_col, last, length, grid, memo);

        cout << length << " " << solution << "\n";

    }
    
    return 0; 
}
