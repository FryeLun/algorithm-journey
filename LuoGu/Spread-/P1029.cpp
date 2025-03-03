#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for(int i = x; i <= y; i++) {
        int j = x * y / i;
        if(gcd(i, j) == x && lcm(i, j) == y) {
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}
