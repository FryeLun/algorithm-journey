#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s, t;
	cin >> s >> t;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++) {
		if(cnt == t.size()) {
			break;
		}
		if(s[i] == t[cnt]) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
