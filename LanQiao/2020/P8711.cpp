#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	ll n;
	cin >> n;
	while(n){
		cout << n << " ";
		n /= 2;
	}
	return 0;
}
