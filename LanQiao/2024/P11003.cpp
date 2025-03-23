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
        ll n;
        cin >> n;
        if(n % 3 == 0) {
            cout << n * 2 << endl;
        } else {
            cout << n << endl;
        }
    }
    return 0;
}
