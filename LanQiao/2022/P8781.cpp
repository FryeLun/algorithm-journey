#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cout << max(n - i, i - 1) * 2 << endl; 
	}
	return 0;
} 
