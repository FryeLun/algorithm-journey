#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	string s, ans;
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= '1' && s[i] <= '9') {
			for(int j = 1; j < s[i] - '0'; j++) {
				ans.push_back(s[i - 1]);
			}
		} else {
			ans.push_back(s[i]);
		}
	}
	cout << ans << endl;
	return 0;
}

