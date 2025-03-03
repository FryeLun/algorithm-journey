#include<bits/stdc++.h>
using namespace std;

bool f(int n) {
	while(n) {
		int tmp = n % 10;
		if(tmp == 2 || tmp == 0 || tmp == 1 || tmp == 9) {
			return true;
		}
		n /= 10;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		if(f(i)) {
			sum += i;
		}
	}
	cout << sum << endl;
	return 0;
}

