#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,a[100005]={},b[100005]={}, ans = 0;;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n / 2; i++) {
		b[i] = a[i] - a[n + 1 - i];	
	}
	for(int i = 1; i <= n / 2; i++) {
		ans += abs(b[i]);
		if(i != n) {
			if(b[i] < 0 && b[i + 1] < 0) {
				b[i + 1] -= max(b[i], b[i + 1]);
			}
			if(b[i] > 0 && b[i + 1] > 0) {
				b[i + 1] -= min(b[i], b[i + 1]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
