// 没有上司的舞会
// 某大学有n个职员，编号为1...n
// 他们之间有从属关系，也就是说他们的关系就像一棵以校长为根的树
// 父结点就是子结点的直接上司
// 现在有个周年庆宴会，宴会每邀请来一个职员都会增加一定的快乐指数 
// 但是如果某个职员的直接上司来参加舞会了
// 那么这个职员就无论如何也不肯来参加舞会了
// 所以请你编程计算邀请哪些职员可以使快乐指数最大
// 返回最大的快乐指数。
// 测试链接 : https://www.luogu.com.cn/problem/P1352
// 本题和讲解037的题目7类似
// 链式链接 : https://leetcode.cn/problems/house-robber-iii/

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 6001;
int nums[MAXN];
bool boss[MAXN];

int head[MAXN];
int nxt[MAXN];
int to[MAXN];
int cnt;

int no[MAXN];
int yes[MAXN];
int n, h;

void build(){
    fill(boss, boss + n + 1, true);
    fill(head, head + n + 1, 0);
    cnt = 1;
}

void addEdge(int u, int v) {
	nxt[cnt] = head[u];
	to[cnt] = v;
	head[u] = cnt++;
}

void f(int u) {
	no[u] = 0;
	yes[u] = nums[u];
	for (int ei = head[u], v; ei > 0; ei = nxt[ei]) {
		v = to[ei];
		f(v);
		no[u] += max(no[v], yes[v]);
		yes[u] += no[v];
	}
}

int main(){
    cin >> n;
    build();
    for(int i = 1;i <= n;i++){
        cin >> nums[i];
    }
    for(int i = 1, low, high; i < n; i++){
        cin >> low >> high;
		addEdge(high, low);
		boss[low] = false;
	}
    for(int i = 1; i <= n; i++){
		if (boss[i]) {
		    h = i;
			break;
		}
	}
	f(h);
    cout << max(no[h], yes[h]) << endl;
    return 0;
}