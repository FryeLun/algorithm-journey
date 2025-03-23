#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int w, m, n;

int f1(int a) {
    if(a % w == 0) {
        return a / w;
    } else {
        return a / w + 1;
    }
}

int f2(int a, int b) {
    if(b % w != 0) {
        if(a % 2 == 0) {
            return w - b % w + 1;
        } else {
            return b % w;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> w >> m >> n;
    int cm =  f1(m), cn = f1(n);
    int ans = abs(cm - cn);
    ans += abs(f2(cm, m) - f2(cn, n));
    cout << ans << endl;
    return 0;
}
