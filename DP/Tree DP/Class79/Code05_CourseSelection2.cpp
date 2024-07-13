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
int edgeCnt;
int head[MAXN];
int nxt[MAXN];
int to[MAXN];
int dfnCnt;
int val[MAXN + 1];
int dfnsize[MAXN + 1];
int dp[MAXN + 2][MAXN];
int n, m;

void build(int n, int m) {
    edgeCnt = 1;
    dfnCnt = 0;
    memset(head, 0, sizeof(head));
    memset(dp, 0, sizeof(dp));
}

void addEdge(int u, int v) {
    nxt[edgeCnt] = head[u];
    to[edgeCnt] = v;
    head[u] = edgeCnt++;
}

int f(int u) {
    int i = ++dfnCnt;
    val[i] = nums[u];
    dfnsize[i] = 1;
    for (int ei = head[u], v; ei > 0; ei = nxt[ei]) {
        v = to[ei];
        dfnsize[i] += f(v);
    }
    return dfnsize[i];
}

int compute() {
    f(0);
    for (int i = n + 1; i >= 2; i--) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i + dfnsize[i]][j], val[i] + dp[i + 1][j - 1]);
        }
    }
    return nums[0] + dp[2][m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    build(n, m);
    for (int i = 1; i <= n; i++) {
        int pre;
        cin >> pre;
        addEdge(pre, i);
        cin >> nums[i];
    }
    cout << compute() << endl;

    return 0;
}
