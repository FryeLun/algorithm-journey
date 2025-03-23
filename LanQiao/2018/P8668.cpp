#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll x, y, n, d = 0;
	cin >> x >> y;
	n = max(abs(x), abs(y));
	d = 2 * n * (2 * n + 1);
	if (y >= 0 && abs(x) <= y) 
		cout << d - 3 * n + x;
	else if (y < 0 && y < x && x <= -y) 
		cout << d + n - x;
	else if (x >= 0 && abs(y) <= x) 
		cout << d - n - y;
	else if (x < 0 && x < y && y <= -x) 
		cout << d - 5 * n + y;
	return 0;
}