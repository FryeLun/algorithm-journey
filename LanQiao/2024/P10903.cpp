#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 5;
int n, m;
int a[N], l[N], r[N], f[N];
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
        a[l[i]]++;
        a[r[i] + 1]--;
    }
    for(int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
        if(a[i] == 0) {
            cnt++;
        }
        f[i] = f[i - 1] + (a[i] == 1);
    }
    for(int i = 1; i <= m; i++) {
        cout << f[r[i]] - f[l[i] - 1] + cnt << endl;
    }
    return 0;
}
