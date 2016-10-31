#include <bits/stdc++.h>

using namespace std;

#define MOD 2000000011

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cout << "Case #" << i + 1 << ": ";
		int n;
		cin >> n;
		if (n <= 2)
			cout << "1\n";
		else {
			int m = n - 2;
			long long ans = 1;
			while (m--) {
				ans = (ans * n) % MOD;
			}
			cout << ans << "\n";
		}
	}
}
