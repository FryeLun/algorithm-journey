// 最大BST子树
// 给定一个二叉树，找到其中最大的二叉搜索树（BST）子树，并返回该子树的大小
// 其中，最大指的是子树节点数最多的
// 二叉搜索树（BST）中的所有节点都具备以下属性：
// 左子树的值小于其父（根）节点的值
// 右子树的值大于其父（根）节点的值
// 注意：子树必须包含其所有后代
// 测试链接 : https://leetcode.cn/problems/largest-bst-subtree/

#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct Info {
    long long MAX;
    long long MIN;
    bool isBst;
    int maxBstSize;

    Info(long long a, long long b, bool c, int d) : MAX(a), MIN(b), isBst(c), maxBstSize(d) {}
};

Info f(TreeNode* x) {
    if (x == nullptr) {
        return Info(LONG_MIN, LONG_MAX, true, 0);
    }
    Info infol = f(x->left);
    Info infor = f(x->right);
    long long maxVal = max(static_cast<long long>(x->val), max(infol.MAX, infor.MAX));
    long long minVal = min(static_cast<long long>(x->val), min(infol.MIN, infor.MIN));
    bool isBst = infol.isBst && infor.isBst && infol.MAX < x->val && x->val < infor.MIN;
    int maxBSTSize;
    if (isBst) {
        maxBSTSize = infol.maxBstSize + infor.maxBstSize + 1;
    } else {
        maxBSTSize = max(infol.maxBstSize, infor.maxBstSize);
    }
    return Info(maxVal, minVal, isBst, maxBSTSize);
}

int largestBSTSubtree(TreeNode* root) {
    return f(root).maxBstSize;
}
