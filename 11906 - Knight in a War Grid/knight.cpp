#include <iostream>
#include <vector>

using namespace std;

void go_jump(int x, int y, vector<vector<int>>& grid, int M, int N)
{
	int jump[8][2] = { { M, N }, { M, -N }, { -M, N }, { -M, -N },
					   { N, M }, { N, -M }, { -N, M }, { -N, -M } };

	grid[x][y] = 0;

	int cnt = 0;
	for (int i = 0; i != 8; ++i)
	{
		size_t new_x = x + jump[i][0], new_y = y + jump[i][1];

		if (new_x < grid.size() && new_y < grid[0].size())
		{
			if (grid[new_x][new_y] != -1)
				++cnt;
			if (grid[new_x][new_y] == -2)
				go_jump(new_x, new_y, grid, M, N);
		}
	}

	// special cases
	if ( M == N || M == 0 || N == 0)
		cnt /= 2;
	grid[x][y] = cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int R, C, M, N;
		cin >> R >> C >> M >> N;
		vector<vector<int>> grid(R, vector<int>(C, -2)); // -1 for water, -2 for unvisited cell
		
		int W;
		cin >> W;
		for (int j = 0; j != W; ++j)
		{
			int x, y;
			cin >> x >> y;
			grid[x][y] = -1;
		}

		go_jump(0, 0, grid, M, N);

		int even = 0, odd = 0;
		for (size_t j = 0; j != grid.size(); ++j)
			for (size_t k = 0; k != grid[0].size(); ++k)
				if (grid[j][k] >= 0)
				{
					if (grid[j][k] % 2)
						++odd;
					else
						++even;
				}

		cout << "Case " << i + 1 << ": " << even << " " << odd << "\n";
	}
	return 0;
}