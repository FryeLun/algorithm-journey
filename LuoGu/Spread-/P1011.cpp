#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    int f[22] ={0};
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    int b = ( m - ( f[n - 3] + 1) * a) / (f[n - 2] - 1);
    cout << (f[x - 2] + 1) * a + (f[x - 1] - 1) * b << endl;
    return 0;
}
