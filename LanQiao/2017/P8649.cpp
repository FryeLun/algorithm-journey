#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> pre(n + 1);
    ll ans = 0;
    map<ll, ll> cnt;
    cnt[0] = 1;
    for(int i = 1, a; i <= n; i++) {
        cin >> a;
        pre[i] = (pre[i - 1] + a) % k;
        cnt[pre[i]]++;
    }
    for(int i = 0; i < k; i++) {
        ans += (ll)(cnt[i] * (cnt[i] - 1)) / 2;
    }
    cout << ans << endl;
    return 0;
}
