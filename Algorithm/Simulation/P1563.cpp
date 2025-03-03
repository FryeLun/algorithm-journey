#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    vector<pair<int, string>> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    int ans = 1;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if(a[ans].first == 0) {
            ans = x == 0 ? ans - y : ans + y;
        } else {
            ans = x == 0 ? ans + y : ans - y;
        }
        if(ans <= 0) {
            ans += n;
        }
        if(ans > n) {
            ans -= n;
        }
    }
    cout << a[ans].second << endl;
    return 0;
}
