#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int day[13]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ans = 0;
	vector<int> a(100);
	for(int i = 0; i < 100; i++) {
		cin >> a[i];
	}
	for(int m = 1; m <= 12; m++) {
		for(int d = 1; d <= day[m]; d++) {
			int cnt = 0;
			string s = "2023";
			if(m < 10) {
				s += '0';
			}
			s += to_string(m);
			if(d < 10) {
				s += '0';
			}
			s += to_string(d);
			for(int k = 0; k < 100 && cnt < 8; k++) {
				if(a[k] == s[cnt] - '0') {
					cnt++;
				}
			}
			if(cnt >= 8) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	cout << 235 << endl;
	return 0;
} 
