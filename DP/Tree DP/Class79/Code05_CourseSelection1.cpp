// 选课
// 在大学里每个学生，为了达到一定的学分，必须从很多课程里选择一些课程来学习
// 在课程里有些课程必须在某些课程之前学习，如高等数学总是在其它课程之前学习
// 现在有 N 门功课，每门课有个学分，每门课有一门或没有直接先修课
// 若课程 a 是课程 b 的先修课即只有学完了课程 a，才能学习课程 b
// 一个学生要从这些课程里选择 M 门课程学习
// 问他能获得的最大学分是多少
// 测试链接 : https://www.luogu.com.cn/problem/P2014

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 301;
int nums[MAXN];
vector<vector<int>> graph;
int dp[MAXN][MAXN][MAXN];
int n, m;

int f(int i, int j, int k) {
    if (k == 0) {
		return 0;
	}
	if (j == 0 || k == 1) {
		return nums[i];
	}
	if (dp[i][j][k] != -1) {
		return dp[i][j][k];
	}
	int ans = f(i, j - 1, k);
    int v = graph[i][j - 1];
    for (int s = 1; s < k; s++) {
        ans = max(ans, f(i, j - 1, k - s) + f(v, graph[v].size(), s));
    }
    dp[i][j][k] = ans;
    return ans;
}

int compute() {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < graph[i].size() + 1; j++) {
            for (int k = 0; k <= m; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    return f(0, graph[0].size(), m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    m += 1;
    graph.clear();
    graph.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int pre;
        cin >> pre;
        graph[pre].push_back(i);
        cin >> nums[i];
    }
    cout << compute() << endl;
    return 0;
}
