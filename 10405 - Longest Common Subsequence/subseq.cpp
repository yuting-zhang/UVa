#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	string st1, st2;
	while (getline(cin, st1)){
		getline(cin, st2);
		int n = st1.size();
		int m = st2.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++){
				if (st1[i - 1] == st2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			}
		cout << dp[n][m] << "\n";
	}
}
