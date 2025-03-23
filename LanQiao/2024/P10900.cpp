#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f(ll a) {
	for(int i = 0; i < 100; i++) {
		if((ll)1 << i == a) {
			return true;
		} else if((ll)1 << i > a){
			return false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	ll a;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> a;
		if(f(a)){
			ans ++;
		}
	}
	cout << ans << endl;
	return 0;
}