// 01背包(模版)
// 给定一个正数t，表示背包的容量
// 有m个货物，每个货物可以选择一次
// 每个货物有自己的体积costs[i]和价值values[i]
// 返回在不超过总容量的情况下，怎么挑选货物能达到价值最大
// 返回最大的价值
// 测试链接 : https://www.luogu.com.cn/problem/P1048
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的所有代码，并把主类名改成"Main"，可以直接通过
#include <bits/stdc++.h>
using namespace std;

const int MAXM = 101;
int t, m;
int cost[MAXM], val[MAXM];

int compute() {
	vector<vector<int>> dp(m + 1, vector<int>(t + 1));
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= t; j++) {
			dp[i][j] = dp[i - 1][j];
			if(j - cost[i] >= 0){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + val[i]);
			}
		}
	}
	return dp[m][t];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t >> m;
	for (int i = 1; i <= m; i++) {
		cin >> cost[i] >> val[i];
	}
	cout << compute() << endl;
	return 0;
}