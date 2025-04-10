#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(string s) {
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        ans = ans * 10 + s[i] - '0';
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 1; i < s.size(); i++) {
            string a = s.substr(0, i);
            string b = s.substr(i);
            ans = max(ans, f(a) + f(b));
        }
        cout << ans << endl;
    }
    return 0;
}
