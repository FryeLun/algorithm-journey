#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	for(int i = n; i > 0; i--) {
		ans++;
		if(ans % 3 == 0) {
			i++;
		}
	}
	cout << ans << endl;
	return 0;
}