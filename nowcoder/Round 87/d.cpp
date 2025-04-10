#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<ll> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + a[i - 1];
            if (i >= 2) {
                dp[i] = max(dp[i], dp[i - 2]);
            }
            if (i >= 3) {
                dp[i] = max(dp[i], dp[i - 3]);
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}