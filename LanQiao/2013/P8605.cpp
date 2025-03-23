#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e4;
const int MAXM = 1e5;
int d[MAXN], u[MAXM], v[MAXM];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	memset(d, 0, sizeof(d));
	for(int i = 0; i < m; i++) {
		cin >> u[i] >> v[i];
		d[u[i]]++;
		d[v[i]]++;
	}
	ll ans = 0;
	for(int i = 0; i < m; i++) {
		if(d[u[i]] > 1 && d[v[i]] > 1) {
			ans += (d[u[i]] - 1) * (d[v[i]] - 1) * 2;
		}
	}
	cout << ans << endl;
	return 0;
}
