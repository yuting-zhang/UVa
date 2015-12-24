#include <iostream>
#include <vector>
#include <fstream>
#include <utility>
#include <queue>

using namespace std;

pair<int,int> BFS (int source, const vector<vector<int>>& relation)
{
    pair<int,int> ret = {0, 0};
    vector<bool> visited(relation.size(), false);
    vector<int> boom_size(relation.size(),0);
    queue<pair<int,int>> Queue;
    Queue.push({source, 0});
    visited[source] = true;
    bool no_friend = true;
    while (!Queue.empty())
    {
        int curr = Queue.front().first,
            day = Queue.front().second;
        ++boom_size[day];
        Queue.pop();
        for (int i = 0; i < relation[curr].size(); ++i)
        {
            if (!visited[relation[curr][i]])
            {
                Queue.push({relation[curr][i], day + 1});
                visited[relation[curr][i]] = true;
                no_friend = false;
            }
        }
    }
    for (int i = 1; i < boom_size.size(); ++i)
        if (boom_size[i] > ret.first)
        {
            ret.first = boom_size[i];
            ret.second = i;
        }

    if (no_friend)
        ret.first = -1;
    return ret;
}

int main()
{
    ifstream fin("news.in");
    int E;
    cin >> E;
    //fin >> E;
    vector<vector<int>> relation(E);
    for (int i = 0; i < E; ++i)
    {
        int N;
        cin >> N;
        //fin >> N;
        for (int j = 0; j < N; ++j)
        {
            int Nj;
            cin >> Nj;
            //fin >> Nj;
            relation[i].push_back(Nj);
        }

    }
    int T;
    cin >> T;
    //fin >> T;
    for (int i = 0; i < T; ++i)
    {
        int source;
        cin >> source;
        //fin >> source;
        auto ret = BFS(source, relation);
        if (ret.first == -1)
            cout << "0\n";
        else
            cout << ret.first << " " << ret.second << "\n";
    }
    return 0;
}
