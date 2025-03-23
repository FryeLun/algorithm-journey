#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int a[1005][1005];
int dx[]={0, 1, 0, -1}, dy[]={1, 0, -1, 0};
int sum = 0, ans = 0, flag, cnt;

void f(int x, int y) {
	if(flag) {
		cnt = 0;
		for(int i = 0; i < 4; i++) {
			if(a[x + dx[i]][y + dy[i]] != 1) {
				cnt++;
			}
		}
		if(cnt == 4) {
			ans++;
			flag = 0;
		}
	}
	a[x][y] = 3;
	for(int i = 0; i < 4; i++) {
		int ax = x + dx[i], ay = y + dy[i];
		if(ax < 1 || ax > n || ay < 1 || ay > n || a[ax][ay] != 2) {
			continue;
		}
		f(ax, ay);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	char c;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> c;
			a[i][j] = c == '.' ? 1 : 2;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i][j] == 2) {
				sum++;
				flag = 1;
				f(i, j);
			}
		}
	}
	cout << sum - ans << endl;
	return 0;
}
