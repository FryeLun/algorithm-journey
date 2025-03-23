#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a, b;

bool f(int n) {
	if(n == 0) {
		return false;
	}
	int m = sqrt(n);
	return m * m == n;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	for(int i = a; i <= b; i++) {
		if(f(i)) {
			string s = to_string(i);
			for(int j = 1; j < s.size(); j++) {
				int x = stoi(s.substr(0, j));
				int y = stoi(s.substr(j));
				if(f(x) && f(y)) {
					cout << i << endl;
					break;
				}
			}	
		}
	}
	return 0;
}