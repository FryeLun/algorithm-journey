#include<bits/stdc++.h>
using namespace std;

bool f(int n){
	while (n) {
		int tmp = n % 10;
		if(tmp == 0 || tmp == 2 || tmp == 4) {
			return true;
		}
		n /= 10;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[100005][2];
	for(int i = 0; i < n; i++) {
		cin >> a[i][0];
	}
	for(int i = 0; i < n; i++) {
		cin >> a[i][1];
	}
	int ans = 0;
	for(int i = 0, where = 0; i < n; i++) {
		if(f(a[i][where])){
			ans++;
			where = !where;
		}
	}
	cout << ans << endl;
	return 0;
}