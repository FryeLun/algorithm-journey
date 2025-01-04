#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN], g[MAXN], k[MAXN];


int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> g[i] >> k[i];
	}
	int x, y, ans = -1;
	cin >> x >> y;
    for (int i = 1; i <= n; i++) {
        if (x >= a[i] && x <= g[i] + a[i] && y >= b[i] && y <= k[i] + b[i]) {
            ans = i;
        }
    }
    cout << ans << endl;
	return 0;
}
