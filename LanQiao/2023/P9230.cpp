#include<bits/stdc++.h>
using namespace std;

int ans = 0;

void f(int i, int sum) {
	if(sum == 70) {
		ans++;
	}
	if(sum == 100 || i == 31) {
		return;
	}
	f(i + 1, sum + 10);
	f(i + 1, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// int ans = 0;
	// for(int i = 11; i < 100000000; i++) {
	// 	string s = to_string(i);
	// 	int len = s.size();
	// 	int a = 0, b = 0;
	// 	if(len % 2 == 0) {
	// 		for(int j = 0; j < len / 2; j++) {
	// 			a += s[j] - '0';
	// 			b += s[len - j - 1] - '0';
	// 		}
	// 		if(a == b) ans++;
	// 	}
	// }
	// cout << ans << endl;
	// cout << 4430091 << endl;

	//2
	// f(1, 0);
	// cout << ans;
	char pid;
    cin >> pid;
    if(pid == 'A')
        puts("4430091");
    else
        puts("8335366");
	return 0;
}
