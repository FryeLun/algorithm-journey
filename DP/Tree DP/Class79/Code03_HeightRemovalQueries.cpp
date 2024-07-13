// 移除子树后的二叉树高度
// 给你一棵 二叉树 的根节点 root ，树中有 n 个节点
// 每个节点都可以被分配一个从 1 到 n 且互不相同的值
// 另给你一个长度为 m 的数组 queries
// 你必须在树上执行 m 个 独立 的查询，其中第 i 个查询你需要执行以下操作：
// 从树中 移除 以 queries[i] 的值作为根节点的子树
// 题目所用测试用例保证 queries[i] 不等于根节点的值
// 返回一个长度为 m 的数组 answer
// 其中 answer[i] 是执行第 i 个查询后树的高度
// 注意：
// 查询之间是独立的，所以在每个查询执行后，树会回到其初始状态
// 树的高度是从根到树中某个节点的 最长简单路径中的边数
// 测试链接 : https://leetcode.cn/problems/height-of-binary-tree-after-subtree-removal-queries/

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    static const int MAXN = 1e5 + 10;
    int dfn[MAXN], deep[MAXN], size[MAXN], maxl[MAXN], maxr[MAXN];
    int dfnCnt;
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfnCnt = 0;
        f(root, 0);
        for(int i = 1; i <= dfnCnt; i++) {
			maxl[i] = max(maxl[i - 1], deep[i]);
		}
		maxr[dfnCnt + 1] = 0;
		for(int i = dfnCnt; i >= 1; i--) {
			maxr[i] = max(maxr[i + 1], deep[i]);
		}
        int n = queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
			int leftMax = maxl[dfn[queries[i]] - 1];
			int rightMax = maxr[dfn[queries[i]] + size[dfn[queries[i]]]];
			ans[i] = max(leftMax, rightMax);
		}
		return ans;
    }

    void f(TreeNode* x, int k) {
		int i = ++dfnCnt;
		dfn[x->val] = i;
		deep[i] = k;
		size[i] = 1;
		if(x->left != nullptr){
			f(x->left, k + 1);
			size[i] += size[dfn[x->left->val]];
		}
		if(x->right != nullptr){
			f(x->right, k + 1);
			size[i] += size[dfn[x->right->val]];
		}
	}
};