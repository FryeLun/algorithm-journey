#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e8;
int m;
ll fib[MAXN];

ll f(int n) {
    if(fib[n]) {
        return fib[n];
    }
    if(n == 1 || n == 2) {
        fib[n] = 1 % m;
    } else {
        fib[n] = (f(n - 1) + f(n - 2)) % m;
    }
    return fib[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    ll ans = 1;
    while(f(ans) != 0 || f(ans + 1) != 1) {
        ans ++;
    }
    cout << ans << endl;
    return 0;
}
