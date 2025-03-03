#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 100003;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    cout << dp[n];
    return 0;
}
