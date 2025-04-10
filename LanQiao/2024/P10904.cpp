#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 5;
int n, m;
int l[N], r[N], ans, zero;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0, a; i < n; i++) {
        cin >> a;
        if(a < 0) {
            l[-a]++;
        } else if(a > 0) {
            r[a]++;
        } else {
            zero++;
        }
    }
    for(int i = 1; i <= m; i++) {
        l[i] += l[i - 1];
        r[i] += r[i - 1];
    }
    for(int i = 1, tmp; i <= m; i++) {
        tmp = l[i];
        if(m - 2 * i > 0) {
            tmp += r[m - 2 * i];
        }
        ans = max(ans, tmp);
        tmp = r[i];
        if(m - 2 * i > 0) {
            tmp += l[m - 2 * i];
        }
        ans = max(ans, tmp);
    }
    cout << ans + zero << endl;
    return 0;
}
