#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 105;
int cost[MAXN], val[MAXN];
int dp[MAXN][1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, m;
    cin >> t >> m;
    for(int i = 1; i <= m; i++) {
        cin >> cost[i] >> val[i];
    }
	vector<vector<int>> dp(m + 1, vector<int>(t + 1));
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= t; j++) {
			dp[i][j] = dp[i - 1][j];
			if(j - cost[i] >= 0){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + val[i]);
			}
		}
	}
    cout << dp[m][t] << endl;
    return 0;
}
