#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    if ((k - 1) / x + 1 == n || k / x == n ) {
        if (k / x == n) {
            cout << 1 << ' ' << k << endl;
        } else {
            cout << x << ' ' << x + k - 1 << endl;
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}
