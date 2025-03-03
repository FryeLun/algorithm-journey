#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    for(int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 1; i <= 2 * n; i += 2) {
        ans += a[i + 1] - a[i];
    }
    cout << ans << endl;
    return 0;
}