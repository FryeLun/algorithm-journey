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
        int n = s.size(), l = 0, r = n - 1, f = 1;
        while(l < n && (s[l] == 'l' || s[l] == 'q' || s[l] == 'b')) l++;
        while(r >= 0 && (s[r] == 'l' || s[r] == 'q' || s[r] == 'b')) r--;
        for(int i = l, j = r; i < j; i++, j--) {
            if(s[i] != s[j]){
                f = 0;
                break;
            }
        }
        if(l + r > n) {
            f = 0;
        } else {
            for(int i = 0; i < l; i++) {
                if(s[l - i - 1] != s[r + i + 1]) {
                    f = 0;
                    break;
                }
            }
        }
        if(f) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
