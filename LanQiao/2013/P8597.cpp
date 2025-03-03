#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a;
    cin >> b;
    int ans = 0;
    for(int i = 0; i < a.size() - 1; i++) {
        if(a[i] != b[i]) {
            ans++;
            a[i] = a[i] == '*' ? 'o' : '*';
            a[i + 1] = a[i + 1] == '*' ? 'o' : '*';
        }
    }
    cout << ans << endl;
    return 0;
}
