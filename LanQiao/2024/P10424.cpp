#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f(int n) {
	int cnt = 0;
	while (n) {
		int tmp = n % 10;
		cnt++;
		if(cnt % 2 == 1 && tmp % 2 != 1) {
			return false;
		}
		if(cnt % 2 == 0 && tmp % 2 != 0) {
			return false;
		}
		n /= 10;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(f(i)) {
			ans++;
		} 
	}
	cout << ans << endl;
	return 0;
}