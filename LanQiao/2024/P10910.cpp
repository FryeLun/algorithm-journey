#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	sort(t.begin(), t.end());
	int a = 0, b = 0;
	string ans = "";
	while(a < n && b < m) {
		while(t[b] < s[a] && b < m) {
			ans += t[b++];
		}
		ans += s[a++];
	}
	if(a < n) {
		ans += s.substr(a);
	}
	if(b < m) {
		ans += t.substr(b);
	}
	cout << ans << endl;
	return 0;
}
