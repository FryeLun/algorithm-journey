#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k, ans = 0;
    string s;
    cin >> k >> s;
    int n = s.size();
    if(n % k != 0) {
        cout << -1 << endl;
    } else {
        for(int i = 0; i < n / k; i++) {
            int smax = 0;
            vector<int> cnt(26);
            for(int j = i; j < n; j += n / k) {
                cnt[s[j] - 'a']++;
            }
            for(int j = 0; j < 26; j++) {
                smax = max(smax, cnt[j]);
            }
            ans += k - smax;
        }
        cout << ans << endl;
    }
    return 0;
}
