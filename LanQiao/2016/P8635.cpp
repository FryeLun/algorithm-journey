#include <bits/stdc++.h>
using namespace std;

int f(int a, int b, int c, int d) {
	return a * a + b * b + c * c + d * d; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int limit = sqrt(n);
	for(int a = 0;; a++) {
		if(f(a, a, a, a) > n) break;
		for(int b = a;; b++) {
			if(f(a, b, b, b) > n) break;
			for(int c = b;;c++) {
				if(f(a, b, c, c) > n){
					break;
				} else {
					int d = sqrt(n - f(a, b, c, 0));
					if(f(a, b, c, d) == n){
						cout << a << " " << b << " " << c << " " << d << endl;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}