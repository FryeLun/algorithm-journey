#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int ans = 0, sum = 0, smax = -1e9, deep = 1;
	for(int i = 1, a; i <= n; i++) {
		cin >> a;
		sum += a;
		if(i == (1 << deep) - 1){
			if(sum > smax) {
				ans = deep;
				smax = sum;
			}
			deep++;
			sum = 0;
		}
	}
	if(sum > smax) {
		ans = deep;
	}
	cout << ans << endl;
	return 0;
}
