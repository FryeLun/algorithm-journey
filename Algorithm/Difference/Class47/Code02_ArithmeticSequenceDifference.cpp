 //一开始1~n范围上的数字都是0，一共有m个操作，每次操作为(l,r,s,e,d)
 //表示在l~r范围上依次加上首项为s、末项为e、公差为d的数列
 //m个操作做完之后，统计1~n范围上所有数字的最大值和异或和
 //测试链接 : https://www.luogu.com.cn/problem/p4231

#include<iostream>
#include<algorithm>
using namespace std;

void set(int l, int r, int s, int e, int d);
void build();

const int maxn = 10000005;
long long arr[maxn];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0, l, r, s, e; i < m; i++) {
		cin >> l >> r >> s >> e;
		set(l, r, s, e, (e - s) / (r - l));
	}
	build();
	long long amax = arr[0], axor = arr[0];
	for (int i = 1; i <= n; i++) {
		amax = max(amax, arr[i]);
		axor ^= arr[i];
	}
	cout << axor << " " << amax;
}

//一开始1~n范围上的数字都是0，一共有m个操作，每次操作为(l,r,s,e,d)
//表示在l~r范围上依次加上首项为s、末项为e、公差为d的数列
void set(int l, int r, int s, int e, int d) {
	arr[l] += s;
	arr[l + 1] += d - s;
	arr[r + 1] -= d + e;
	arr[r + 2] += e;
}

void build() {
	for (int i = 1; i <= n; i++) {
		arr[i] += arr[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		arr[i] += arr[i - 1];
	}
}