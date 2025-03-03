#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
const int MAXN = 1e5 + 5;
int a[MAXN][2];

bool check(int m) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (a[i][0] / m) * (a[i][1] / m);
    }
    return sum >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    int l = 1, r = MAXN;
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    while(l < r) {
        int mid = (l + r + 1) / 2;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}
