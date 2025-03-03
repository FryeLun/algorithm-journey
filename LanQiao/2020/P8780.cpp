#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b, n;
    cin >> a >> b >> n;
    ll sum = 5 * a + 2 * b;
    ll ans = n / sum * 7;
    n %= sum;
    while(n > 0) {
        ans++;
        if(ans % 7 == 0 || ans % 7 == 6) {
            n -= b;
        } else {
            n -= a;
        }
    }
    cout << ans << endl;
    return 0;
}
