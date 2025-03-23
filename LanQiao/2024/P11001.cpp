#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, int> m1, m2;
    int a, ans = 0;
    for(int i = 1 ; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a;
            ans += m1[make_pair(i + j, a)]++;
            ans += m2[make_pair(i - j, a)]++;
        }
    }
    cout << ans * 2 << endl;
    return 0;
}
