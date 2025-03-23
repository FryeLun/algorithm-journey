#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int rule[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

int f(int n) {
    int ans = 0;
    while(n) {
        ans += rule[n % 10];
        n /= 10;
    }
    return ans;
}

bool cmp(int a, int b) {
    int cnt1 = f(a), cnt2 = f(b);
    if(cnt1 < cnt2) {
        return true;
    } else if(cnt1 == cnt2) {
        return a < b;
    } else {
        return false;
    }
}

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
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
