#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int day[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int y) {
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

bool f(int i) {
	int y = i / 10000;
	int m = i / 1000 % 10 * 10 + i / 100 % 10;
	int d = i / 10 % 10 * 10 + i % 10;
	day[2] = isLeap(y) ? 29 : 28;
	if(m < 0 || m > 12 || d > day[m] || d < 0) {
		return false;
	}
	return true;
}

bool check_huiwen(string s) {
	if(s[0] == s[7] && s[1] == s[6] && s[2] == s[5] && s[3] == s[4]) {
		return true;
	}
	return false;
}

bool check_AB(string s) {
	if(check_huiwen(s)) {
		if(s[0] == s[2] && s[1] == s[3]) {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int flag = 0;
	for(int i = n + 1; ; i++) {
		if(f(i)) {
			string s = to_string(i);
			if(flag == 0 && check_huiwen(s)) {
				cout << i << endl;
				flag = 1;
			}
			if(flag == 1 && check_AB(s)) {
				cout << i << endl;
				return 0;
			}
		}
	}
	return 0;
}