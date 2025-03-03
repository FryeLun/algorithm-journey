#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[20][20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) {
        dp[0][i] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(i == j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }
    cout << dp[n][n] << endl;;
    return 0;
}
