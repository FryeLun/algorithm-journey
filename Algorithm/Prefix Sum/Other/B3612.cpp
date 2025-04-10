#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, a;
	cin >> n;
	vector<int> pre(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> a;
		pre[i] = pre[i - 1] + a;
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		cout << pre[r] -pre[l - 1] << endl;
	}
	return 0;
}