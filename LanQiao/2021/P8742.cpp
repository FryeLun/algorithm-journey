#include<bits/stdc++.h>
using namespace std;

int a[101];
int dp[101][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int sum = 0, ans = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = sum; j;j--) {
			if(j == a[i]) {
				dp[i][j] = 1;
			} else if(dp[i - 1][j]) {
				dp[i][j] = 1;
			} else if(dp[i - 1][j + a[i]]) {
				dp[i][j] = 1;
			} else if(dp[i - 1][abs(j - a[i])]){
				dp[i][j] = 1;
			}
		}
	}
	for(int i = 0;i <= sum; i++) {
		if(dp[n][i]) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}                                                                                                                                                                                                                                                                                                                           
