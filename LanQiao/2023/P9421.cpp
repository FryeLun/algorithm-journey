#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 1; i <= 100005; i++) {
        if(cnt[i] >= 2) {
            ans1 += cnt[i] - 2;
        } else {
            ans2 += cnt[i];
        }
    }
    if(ans1 > ans2) {
        cout << ans1 << endl;
    } else {
        cout << ans1 + (ans2 - ans1) / 2 << endl;
    }
    return 0;
}
