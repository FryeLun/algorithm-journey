#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[500005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int k;
	string s;
	char c1, c2;
	cin >> k >> s >> c1 >> c2;
	ll ans = 0, b = 1;
	for(int i = s.size() - 1; i >= 0; i--) {
		if(s[i] == c2) {
			cnt[i] = b++;
		}
	}
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == c1) {
			for(int j = i + k - 1; j < s.size(); j++) {
				if(s[j] == c2) {
					ans += cnt[j];
					break;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}