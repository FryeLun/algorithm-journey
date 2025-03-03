#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n, sum = 0, nmax = 0, nmin = 101;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		nmax = max(nmax, a);
		nmin = min(nmin, a);
		sum += a;
	}
	printf("%d\n%d\n%.2f\n", nmax, nmin, 1.0 * sum / n);
	return 0;
}

