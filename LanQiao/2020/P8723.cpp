#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

char f1(int a) {
	if(a % n >= 10) {
		return a % n + 'A' - 10;
	} else {
		return a % n + '0';
	}
}

string f2(int a) {
	string s;
	while(a) {
		s += f1(a);
		a /= n;
	}
	reverse(s.begin(), s.end());
	return s;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++) {
		for(int j = 1; j <= i; j++) {
			cout << f1(i) << '*' << f1(j) << '=' << f2(i * j) << " ";
		}
		cout << endl;
	}
	return 0;
} 
