#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp (pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    m = m * 15 / 10;
    int score = 0, cnt = 0;
    for(int i = m; i < n; i++) {
        if(a[i].second == a[m - 1].second) {
            cnt++;
        }
    }
    cout << a[m - 1].second << " " << m + cnt << endl; 
    for(int i = 0; i < m + cnt; i++) {
        cout << a[i].first << " " << a[i].second << endl;
    }
    return 0;
}
