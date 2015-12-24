#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void DPS(const vector<int>& letters, const vector<vector<int>>& edges, vector<string>& answer,
         string& curr_answer, vector<int> zeros, int curr, vector<int>& in_degrees, vector<bool>& visited)
{
    curr_answer += static_cast<char>(curr + 'A');
    if (curr_answer.size() == letters.size())
    {
        answer.push_back(curr_answer);
        curr_answer.pop_back();
        return;
    }

    visited[curr] = true;

    for (int i = 0; i < edges[curr].size(); ++i)
    {
        if (--in_degrees[edges[curr][i]] == 0)
            zeros.push_back(edges[curr][i]);
    }


    for (int i = 0; i < zeros.size(); ++i)
    {
        int next = zeros[i];
        if (!visited[next])
            DPS(letters, edges, answer, curr_answer, zeros, next, in_degrees, visited);
    }

    visited[curr] = false;
    curr_answer.pop_back();

    for (int i = 0; i < edges[curr].size(); ++i)
    {
        ++in_degrees[edges[curr][i]];
    }


}

int main()
{
    ifstream fin("ordering.in");
    istream& in(cin);

    int N;
    in >> N;
    string line;
    getline(in, line); // to next line

    for (int i = 0; i < N; ++i)
    {
        if (i != 0)
            cout << "\n";
        getline(in, line); // empty line
        getline(in, line);
        istringstream sin(line);
        vector<int> letters;
        while (sin)
        {
            char ch;
            sin >> ch;
            if (!sin)
                break;
            letters.push_back(ch - 'A');
        }

        getline(in, line);
        sin.clear();
        sin.str(line);

        vector<int> in_degrees(26, 0);
        vector<vector<int>> edges(26);
        while(sin)
        {
            char left, right;
            sin >> left >> right >> right;
            if (!sin)
                break;
            ++in_degrees[right - 'A'];
            edges[left - 'A'].push_back(right - 'A');
        }

        vector<int> zeros;
        for (int j = 0; j < letters.size(); ++j)
            if (in_degrees[letters[j]] == 0)
                zeros.push_back(letters[j]);

        vector<string> answer;
        string curr_answer;
        vector<bool> visited(26,false);
        for (int j = 0; j < letters.size(); ++j)
            if (in_degrees[letters[j]] == 0)
                DPS(letters, edges, answer, curr_answer, zeros, letters[j], in_degrees, visited);

        if (!answer.empty())
        {
            sort(answer.begin(), answer.end());
            for (int j = 0; j < answer.size(); ++j)
            {
                cout << answer[j][0];
                for (int k = 1; k < answer[j].size(); ++k)
                    cout << " " << answer[j][k];
                cout << "\n";
            }
        }
        else
            cout << "NO\n";
    }

}
