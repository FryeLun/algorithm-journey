// 从树中删除边的最小分数
// 存在一棵无向连通树，树中有编号从0到n-1的n个节点，以及n-1条边
// 给你一个下标从0开始的整数数组nums长度为n，其中nums[i]表示第i个节点的值
// 另给你一个二维整数数组edges长度为n-1
// 其中 edges[i] = [ai, bi] 表示树中存在一条位于节点 ai 和 bi 之间的边
// 删除树中两条不同的边以形成三个连通组件，对于一种删除边方案，定义如下步骤以计算其分数：
// 分别获取三个组件每个组件中所有节点值的异或值
// 最大 异或值和 最小 异或值的 差值 就是这种删除边方案的分数
// 返回可能的最小分数
// 测试链接 : https://leetcode.cn/problems/minimum-score-after-removals-on-a-tree/

#include <vector>
#include <climits>
using namespace std;

class Solution {
private:
    static const int MAXN = 1001;
    int dfn[MAXN], xr[MAXN], size[MAXN];
    int dfnCnt;
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> graph(n);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        fill(dfn, dfn + n, 0);
        dfnCnt = 0;
		f(nums, graph, 0);
        int m = edges.size();
        int ans = INT_MAX;
        for (int i = 0, a, b, pre, pos, sum1, sum2, sum3; i < m; i++) {
			a = max(dfn[edges[i][0]], dfn[edges[i][1]]);
			for (int j = i + 1; j < m; j++) {
				b = max(dfn[edges[j][0]], dfn[edges[j][1]]);
				if (a < b) {
					pre = a;
					pos = b;
				} else {
					pre = b;
					pos = a;
				}
				sum1 = xr[pos];
				if (pos < pre + size[pre]) {
					sum2 = xr[pre] ^ xr[pos];
					sum3 = xr[1] ^ xr[pre];
				} else {
					sum2 = xr[pre];
					sum3 = xr[1] ^ sum1 ^ sum2;
				}
				ans = min(ans, max(max(sum1, sum2), sum3) - min(min(sum1, sum2), sum3));
			}
		}
		return ans;
    }

    void f(vector<int>& nums, vector<vector<int>>& graph, int u){
        int i = ++dfnCnt;
		dfn[u] = i;
		xr[i] = nums[u];
		size[i] = 1;
		for(int v : graph[u]){
			if (dfn[v] == 0) {
				f(nums, graph, v);
				xr[i] ^= xr[dfn[v]];
				size[i] += size[dfn[v]];
			}
		}
    }
};