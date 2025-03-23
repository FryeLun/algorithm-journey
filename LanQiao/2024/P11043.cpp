#include <bits/stdc++.h>
using namespace std;

int node[12];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	int a;
	while(cin >> s) {
		if(s == "add") {
			cin >> a;
			node[0]++;
		} else if(s == "sync") {
			cin >> a;
			node[a]++;
		} else if(s == "query") {
			int ans = 100005;
			for(int i = 0; i < n; i++) {
				ans = min(node[i], ans);
			}
			cout << ans << endl;
		}
	}
	return 0;
}
