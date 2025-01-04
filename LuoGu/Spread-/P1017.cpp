#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char num[] = "0123456789ABCDEFGHIJ";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, r;
    cin >> n >> r;
    cout << n << '=';
    string ans;
    while (n) {
        int m = n % r;
        if (m < 0) {
            m -= r;
            n += r;
        }
        n /= r;
        ans += num[m];
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "(base" << r << ")";
    return 0;
}
