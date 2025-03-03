#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
const int MAXN = 50005;
int dis[MAXN];

bool check(int mid) {
    int del = 0, last = 0;
    for(int i = 1; i <= n + 1; i++) {
        if(dis[i] - dis[last] < mid) {
            del++;
        } else {
            last = i;
        }
    }
    return del <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> dis[i];
    }
    dis[n + 1] = k;
    int l = 1, r = k, mid;
    int ans;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(check(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
