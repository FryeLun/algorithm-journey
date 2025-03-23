#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll w, h;
	cin >> w >> h;
	int x = __gcd(w, h);
	if(x == 1) {
		cout << 0 << endl;
		return 0;
	}
	for(int i = 2; i * i < x; i++) {
		if(w % i == 0 && h % i == 0) {
			cout << (w / i) * (h / i) << endl;
			return 0;
		}
	}
	cout << (w / x) * (h / x) << endl;
	return 0;
}