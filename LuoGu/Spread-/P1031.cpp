#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int num[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int k = 0;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
        k += num[i];
    }
    k /= n;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(num[i] - k) {
            num[i + 1] += num[i] - k;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
