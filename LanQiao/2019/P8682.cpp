#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	return a % b == 0 ? b : gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int d = arr[1] - arr[0];
	if(d == 0) {
		cout << n << endl;
		return 0;
	} else {
		for(int i = 1; i < n - 1; i++) {
			d = min(d, gcd(d, arr[i + 1] - arr[i]));
		}
		cout << (arr[n - 1] - arr[0]) / d + 1 << endl;
	}
	return 0;
}
