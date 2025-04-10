#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
ll n, s;

struct Node{
	ll p, c;
};

bool cmp(const Node &a, const Node &b) {
	return a.c < b.c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s;
	vector<Node> a(n);
	ll sum = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i].p >> a[i].c;
		sum += a[i].p;
	}
	sort(a.begin(), a.end(), cmp);
	ll cnt = 0;
	for(int i = 0; i < n; i++) {
		if(sum < s) {
			ans += a[i].p * (a[i].c - cnt);
		} else {
			ans += s * (a[i].c - cnt);
			sum -= a[i].p;
			cnt += (a[i].c - cnt);
		}
	}
	cout << ans << endl;
	return 0;
}