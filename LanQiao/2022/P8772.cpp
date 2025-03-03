#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<ll> sum(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sum[n] = a[n];
    for(int i = n - 1; i >= 1; i--) {
        sum[i] = sum[i + 1] + a[i];
    }
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        ans += sum[i + 1] * a[i];
    }
    cout << ans << endl;
    return 0;
}
