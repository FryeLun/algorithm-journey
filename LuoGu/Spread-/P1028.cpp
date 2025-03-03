#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = 1;
        for (int j = i / 2; j > 0; j--) {
            dp[i] += dp[j];
        }
    }
    cout << dp[n] << endl;
    return 0;
}
