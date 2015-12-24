#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool DPS(const vector<vector<int>>& tasks, vector<int>& prereq,
         vector<bool>& visited, vector<int>& answer, int curr)
{
    if (prereq[curr] || visited[curr])
        return false;

    answer.push_back(curr + 1);
    visited[curr] = true;

    if (answer.size() == tasks.size())
    {
        cout << answer[0];
        for (int i = 1; i < answer.size(); ++i)
            cout << " " << answer[i];
        return true;
    }

    for (int i = 0; i < tasks[curr].size(); ++i)
        --prereq[tasks[curr][i]];

    return false;
}

int main()
{
    //ifstream fin("tasks.in");
    istream& in(cin);

    while (in)
    {
        int n, m;
        in >> n >> m;
        if (n == 0 && m == 0)
            break;
        vector<vector<int>> tasks(n);
        vector<int> prereq(n);
        for (int k = 0; k < m; ++k)
        {
            int i, j;
            in >> i >> j;
            tasks[i - 1].push_back(j - 1);
            ++prereq[j - 1];
        }

        vector<bool> visited(n, false);
        vector<int> answer;

        int curr = 0;
        while (true)
        {
            if (DPS(tasks, prereq, visited, answer, curr))
                break;
            ++curr;
            if (curr == n)
                curr = 0;
        }
        cout << "\n";
    }

    return 0;
}
