#include<bits/stdc++.h>
using namespace std;

bool f(int y){
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b, c;
	scanf("%d/%d/%d", &a, &b, &c);
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for(int y = 1960; y <= 2059; y++) {
		days[2] = f(y) ? 29 : 28;
		for(int m = 1; m <= 12; m++) {
			for(int d = 1; d <= days[m]; d++) {
				if(((y % 100 == a) && (m == b) && (d == c)) ||
				((m == a) && (d == b) && (y % 100 == c)) ||
				((d == a) && (m == b) && (y % 100 == c))) {
					printf("%d-%02d-%02d\n", y, m, d);
				}
			}
		}
	}
	return 0;
}
