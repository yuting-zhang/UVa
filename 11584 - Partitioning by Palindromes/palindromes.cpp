#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ifstream fin("palindromes.in");
    istream& in(cin);

    int n;
    in >> n;
    for (int i = 0; i < n; ++i)
    {
        string line;
        in >> line;

        // use DP to initialize is_palindromes
        vector<vector<bool>> is_palindromes(line.size(), vector<bool>(line.size(), false));
        for (int j = 0; j < line.size(); ++j)
            is_palindromes[j][j] = true;
        for (int j = 2; j <= line.size(); ++j)
            for (int k = 0; k <= line.size() - j; ++k)
            {

                if (line[k] == line[k + j - 1])
                    if (j == 2 || is_palindromes[k + 1][k + j - 2])
                        is_palindromes[k][k + j - 1] = true;
            }

        // use DP to calculate the result
        vector<int> dp(line.size() + 1, line.size());
        dp[0] = 0;
        for (int i = 1; i <= line.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (is_palindromes[j][i - 1] && dp[j] + 1 < dp[i])
                    dp[i] = dp[j] + 1;
        cout << dp[line.size()] << "\n";
    }
    return 0;
}
