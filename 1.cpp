#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, ans;
int f[12];

struct Node{
  int t, d, l;
}a[12];

void dfs(int i, int time) {
  if(ans) return;
  if(i == n) {
    ans = 1;
    return;
  }
  for(int j = 1; j <= n; j++) {
    if(!f[j] && a[j].t + a[j].d >= time) {
      f[j] = 1;
      dfs(i + 1, max(time, a[j].t) + a[j].l);
      if(ans) return;
      f[j] = 0;
    }
  }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
      cin >> n;
      for(int i = 1; i <= n; i++) {
        cin >> a[i].t >> a[i].d >> a[i].l;
        f[i] = 0;
      }
      ans = 0;
      dfs(0, 0);
      if(ans) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
    return 0;
}
