#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int f1(int n, int p) {
	int sum = 0;
	while(n) {
		sum += n % p;
		n /= p;
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
//	int ans = 0;
//	for(int i = 1; i <= 2024; i++) {
//		if(f1(i, 2) == f1(i, 4)) {
//			ans++;
//		}
//	}
//	cout << ans << endl;
	cout << 63 << endl;
	return 0;
} 
