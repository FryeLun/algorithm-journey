#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for(int i = 1; i <= n; i++) {
		dp[i][1] = 1;
	}
	for(int j = 1; j <= m; j++) {
		dp[1][j] = 1;
	}
	for(int i= 2; i <= n; i++) {
		for(int j = 2; j <= m; j++) {
			if(i % 2 == 0 && j % 2 == 0) {
				dp[i][j] = 0;
			} else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}