#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int m = n * 10 / 2, ans = 0;
    for(int i = 1; i < n; i++) {
        if(i * i % n * 10 < m) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
