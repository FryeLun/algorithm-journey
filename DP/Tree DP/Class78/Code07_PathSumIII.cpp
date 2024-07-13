// 路径总和 III
// 给定一个二叉树的根节点 root ，和一个整数 targetSum
// 求该二叉树里节点值之和等于 targetSum 的 路径 的数目
// 路径 不需要从根节点开始，也不需要在叶子节点结束
// 但是路径方向必须是向下的（只能从父节点到子节点）
// 测试链接 : https://leetcode.cn/problems/path-sum-iii/

#include <unordered_map>
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
    unordered_map<long long, int> presum;
    int ans;
public:
    int pathSum(TreeNode* root, int targetSum) {
        presum[0] = 1;
        ans = 0;
		f(root, targetSum, 0);
		return ans;
    }

    void f(TreeNode* x, int target, long long sum) {
		if (x != nullptr) {
		    sum += x->val;
			ans += presum[sum - target];
			presum[sum]++;
            f(x->left, target, sum);
            f(x->right, target, sum);
            presum[sum]--;
	    }
    }
};