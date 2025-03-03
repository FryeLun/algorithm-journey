#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	map<string, int> m;
	m["Jan"] = 1, m["Feb"] = 2, m["Mar"] = 3, m["Apr"] = 4, m["May"] = 5, m["Jun"] = 6;
	m["Jul"] = 7, m["Aug"] = 8, m["Sep"] = 9, m["Oct"] = 10, m["Nov"] = 11, m["Dec"] = 12;
	string s;
	cin >> s;
	string mon = s.substr(0, 3);
	string day = s.substr(3, 2);
	int num = (day[0] - '0') * 10 + day[1] - '0'; 
	cout << m[mon] << " " << num << endl;
	return 0;
}

