#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    for(int i = 0; i < 5; i++) {
        int y;
        cin >> y;
        if(y / 1000 == y / 10 % 10 && y % 10 == y / 100 % 10 + 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
