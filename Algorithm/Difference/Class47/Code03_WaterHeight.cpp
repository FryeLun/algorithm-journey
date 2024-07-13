// 一群人落水后求每个位置的水位高度
// 测试链接 : https://www.luogu.com.cn/problem/P5026

#include<iostream>
#include<algorithm>
using namespace std;

void fall(int v, int x);
void set(int l, int r, int s, int e, int d);
void build();

const int MAXN = 1000001;
const int OFFSET = 30001;
int arr[OFFSET + MAXN + OFFSET];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0, v, x; i < n; i++) {
		cin >> v >> x;
		fall(v, x);
	}
	build();
	int start = OFFSET + 1;
	cout << arr[start++];
	for (int i = 2; i <= m; i++) {
		cout << " " << arr[start++];
	}
}

void fall(int v, int x) {
	set(x - 3 * v + 1, x - 2 * v, 1, v, 1);
	set(x - 2 * v + 1, x, v - 1, -v, -1);
	set(x + 1, x + 2 * v, -v + 1, v, 1);
	set(x + 2 * v + 1, x + 3 * v - 1, v - 1, 1, -1);
}

void set(int l, int r, int s, int e, int d) {
	arr[l + OFFSET] += s;
	arr[l + 1 + OFFSET] += d - s;
	arr[r + 1 + OFFSET] -= d + e;
	arr[r + 2 + OFFSET] += e;
}

void build() {
	for (int i = 1; i <= m + OFFSET; i++) {
		arr[i] += arr[i - 1];
	}
	for (int i = 1; i <= m + OFFSET; i++) {
		arr[i] += arr[i - 1];
	}
}