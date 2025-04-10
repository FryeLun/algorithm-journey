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
        int n;
        string s;
        cin >> n >> s;
        string a, b;
        for(int i = 0; i < n; i++) {
            a += "AB";
            b += "BA";
        }
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != a[i]) {
                cnt1++;
            }
            if(s[i] != b[i]) {
                cnt2++;
            }
        }
        cout << min(cnt1, cnt2) / 2 << endl;
    }
    return 0;
}
