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
        string s;
        cin >> s;
        int cnt = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] != s[i - 1]) {
                cnt++;
            }
        }
        if(cnt <= 5) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
