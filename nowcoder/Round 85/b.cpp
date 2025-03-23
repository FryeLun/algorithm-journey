#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int x = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            x += a[i];
        } else {
            x -= a[i];
        }
    }
    cout << x << endl;
    return 0;
}
