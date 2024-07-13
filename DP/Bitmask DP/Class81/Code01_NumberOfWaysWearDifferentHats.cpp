// 每个人戴不同帽子的方案数
// 总共有 n 个人和 40 种不同的帽子，帽子编号从 1 到 40
// 给你一个整数列表的列表 hats ，其中 hats[i] 是第 i 个人所有喜欢帽子的列表
// 请你给每个人安排一顶他喜欢的帽子，确保每个人戴的帽子跟别人都不一样，并返回方案数
// 由于答案可能很大，请返回它对10^9+7取余后的结果
// 测试链接 : https://leetcode.cn/problems/number-of-ways-to-wear-different-hats-to-each-other

#include <vector>
using namespace std;

class Solution {
private:
    static const int MOD = 1e9 + 7;

public:
    int numberWays(vector<vector<int>>& arr) {
        int m = 0;
        for (auto person : arr) {
            for (int hat : person) {
                m = max(m, hat);
            }
        }
        int n = arr.size();
        vector<int> hats(m + 1);
        for (int pi = 0; pi < n; pi++) {
            for (int hat : arr[pi]) {
                hats[hat] |= 1 << pi;
            }
        }
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, -1));
        return f2(hats, m, n, 1, 0, dp);
    }

    int f1(vector<int>& hats, int m, int n, int i, int s, vector<vector<int>>& dp) {
        if (s == (1 << n) - 1) {
            return 1;
        }
        if (i == m + 1) {
            return 0;
        }
        if (dp[i][s] != -1) {
            return dp[i][s];
        }
        int ans = f1(hats, m, n, i + 1, s, dp);
        int cur = hats[i];
        for (int p = 0; p < n; p++) {
            if ((cur & (1 << p)) != 0 && (s & (1 << p)) == 0) {
                ans = (ans + f1(hats, m, n, i + 1, s | (1 << p), dp)) % MOD;
            }
        }
        dp[i][s] = ans;
        return ans;
    }

    int f2(vector<int>& hats, int m, int n, int i, int s, vector<vector<int>>& dp) {
        if (s == (1 << n) - 1) {
            return 1;
        }
        if (i == m + 1) {
            return 0;
        }
        if (dp[i][s] != -1) {
            return dp[i][s];
        }
        int ans = f2(hats, m, n, i + 1, s, dp);
        int cur = hats[i];
        int rightOne;
        while (cur != 0) {
            rightOne = cur & -cur;
            if ((s & rightOne) == 0) {
                ans = (ans + f2(hats, m, n, i + 1, s | rightOne, dp)) % MOD;
            }
            cur ^= rightOne;
        }
        dp[i][s] = ans;
        return ans;
    }
};