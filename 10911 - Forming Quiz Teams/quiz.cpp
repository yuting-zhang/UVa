#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cmath>

#define MAXINT 1000000000
using namespace std;

typedef pair<int,int> point;

void DPS(vector<bool>& paired, int N, vector<int>& pairs, vector<vector<double>>& dist, double& answer, double& curr_sum)
{
    if (N == 0)
    {
        answer = min(curr_sum, answer);
        return;
    }

    int curr = 0;
    while (paired[curr])
        ++curr;

    paired[curr] = true;

    for (int i = curr + 1; i < paired.size(); ++i)
        if (!paired[i])
        {
            curr_sum += dist[i][curr];
            if (curr_sum > answer)
            {
                curr_sum -= dist[i][curr];
                continue;
            }
            paired[i] = true;
            pairs[i] = curr;
            pairs[curr] = i;
            DPS(paired, N - 2, pairs, dist, answer, curr_sum);
            paired[i] = false;
            curr_sum -= dist[i][curr];
        }

    paired[curr] = false;
}

int main()
{
    ifstream fin("quiz.in");
    istream& in(cin);

    int test_case = 0;
    while (in)
    {
        ++test_case;
        int N;
        in >> N;
        if (N == 0)
            break;
        vector<point> coordinates(2 * N);
        for (int i = 0; i < N * 2; ++i)
        {
            string name;
            in >> name;
            in >> coordinates[i].first >> coordinates[i].second;
        }

        vector<vector<double>> dist(2 * N, vector<double>(2 * N, 0));
        for (int i = 0; i < 2 * N; ++i)
            for (int j = 0; j < 2 * N; ++j)
                dist[i][j] = sqrt(pow(coordinates[i].first - coordinates[j].first, 2) +
                                  pow(coordinates[i].second - coordinates[j].second, 2));

        vector<bool> paired(2 * N, false);
        vector<int> pairs(2 * N);
        double answer = MAXINT;
        double curr_sum = 0;
        DPS(paired, 2 * N, pairs, dist, answer, curr_sum);
        printf("Case %d: %.2f\n", test_case, answer);
    }
    return 0;
}
