#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, ans = 0;
        cin >> n;
        vector<int> a(n + 1);
        vector<int> b(n + 1);
        for(int i = 1, num; i <= n; i++) {
            cin >> num;
            if(num < 0) {
                a[i] = -1;
            } else if(num > 0) {
                a[i] = 1;
            } else {
                a[i] = 0;
            }
        }
        for(int i = 1; i <= n; i++) {
            char c;
            cin >> c;
            if(c == '<') {
                b[i] = -1;
            } else if(c == '>') {
                b[i] = 1;
            } else {
                b[i] = b[i - 1];
            }
        }
        for(int i = 1; i <= n; i++) {
            if(a[i] != b[i]) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}