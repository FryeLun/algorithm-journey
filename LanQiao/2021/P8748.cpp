#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	n /= 1000;
	printf("%02d:%02d:%02d", n % 86400 / 3600, n % 3600 / 60, n % 60);
	return 0;
}
