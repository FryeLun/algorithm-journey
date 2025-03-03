#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int v, n;
    cin >> v >> n;
    vector<int> cost(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    vector<int> dp(v + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = v; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + cost[i]);
        }
    }
    cout << v - dp[v] << endl;
    return 0;
}
