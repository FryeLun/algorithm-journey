#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
ll n, s, p[MAXN], c[MAXN], tmp[MAXN], sum, ans, all;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s;
	for(int i = 1; i <= n; i++) {
		cin >> p[i] >> c[i];
		tmp[c[i]] += p[i];
		sum += p[i];
		all += p[i] * c[i];
	}
	for(int i = 1; i <= 1e6; i++) {
		if(sum < s){
			break;
		}
		ans += s;
		all -= sum;
		sum -= tmp[i];
	}
	cout << ans + all << endl;
	return 0;
}