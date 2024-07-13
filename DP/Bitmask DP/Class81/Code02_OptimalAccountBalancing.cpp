// 最优账单平衡
// 给你一个表示交易的数组 transactions
// 其中 transactions[i] = [fromi, toi, amounti]
// 表示 ID = fromi 的人给 ID = toi 的人共计 amounti
// 请你计算并返回还清所有债务的最小交易笔数
// 测试链接 : https://leetcode.cn/problems/optimal-account-balancing/

#include <vector>
#include <algorithm>
using namespace std;

class OptimalAccountBalancing {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        const int MAXN = 13;
        vector<int> debt = debts(transactions);
        int n = debt.size();
        vector<int> dp(1 << n, -1);
        return n - f(debt, (1 << n) - 1, 0, n, dp);
    }

    vector<int> debts(vector<vector<int>>& transactions) {
        const int MAXN = 13;
        vector<int> help(MAXN, 0);
        for (const auto& tran : transactions) {
            help[tran[0]] -= tran[2];
            help[tran[1]] += tran[2];
        }
        vector<int> debt;
        for (int num : help) {
            if (num != 0) {
                debt.push_back(num);
            }
        }
        return debt;
    }

    int f(vector<int>& debt, int set, int sum, int n, vector<int>& dp) {
        if (dp[set] != -1) {
            return dp[set];
        }
        int ans = 0;
        if ((set & (set - 1)) != 0) {
            if (sum == 0) {
                for (int i = 0; i < n; i++) {
                    if ((set & (1 << i)) != 0) {
                        ans = f(debt, set ^ (1 << i), sum - debt[i], n, dp) + 1;
                        break;
                    }
                }
            } else {
                for (int i = 0; i < n; i++) {
                    if ((set & (1 << i)) != 0) {
                        ans = max(ans, f(debt, set ^ (1 << i), sum - debt[i], n, dp));
                    }
                }
            }
        }
        dp[set] = ans;
        return ans;
    }
};
