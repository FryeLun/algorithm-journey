// 划分为k个相等的子集
// 给定一个整数数组  nums 和一个正整数 k，
// 找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
// 测试链接 : https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/

#include <vector>
#include <algorithm>
using namespace std;

// 状压dp的解法
// 这是最正式的解
class Solution1 {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        if(sum % k != 0){
            return false;
        }
        int n = nums.size();
        vector<int> dp(1 << n, 0);
        return f(nums, sum / k, (1 << n) - 1, 0, k, dp);
    }

    bool f(vector<int>& nums, int limit, int status, int cur, int rest, vector<int>& dp){
        if (rest == 0) {
			return status == 0;
		}
		if (dp[status] != 0) {
			return dp[status] == 1;
		}
		bool ans = false;
		for (int i = 0; i < nums.size(); i++) {
			if ((status & (1 << i)) != 0 && cur + nums[i] <= limit) {
				if (cur + nums[i] == limit) {
					ans = f(nums, limit, status ^ (1 << i), 0, rest - 1, dp);
				} else {
					ans = f(nums, limit, status ^ (1 << i), cur + nums[i], rest, dp);
				}
				if (ans) {
					break;
				}
			}
		}
		dp[status] = ans ? 1 : -1;
		return ans;
    }
};

// 纯暴力的递归（不做任何动态规划），利用良好的剪枝策略，可以做到非常好的效率
// 但这并不是正式的解，如果数据设计的很苛刻，是通过不了的
class Solution2 {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        if(sum % k != 0){
            return false;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> group(k);
        return f(group, sum / k, nums, n - 1);
    }

    bool f(vector<int>& group, int target, vector<int>& nums, int index){
        if (index < 0) {
			return true;
		}
		int num = nums[index];
		int len = group.size();
		for (int i = 0; i < len; i++) {
			if (group[i] + num <= target) {
				group[i] += num;
				if (f(group, target, nums, index - 1)) {
					return true;
				}
				group[i] -= num;
				while (i + 1 < group.size() && group[i] == group[i + 1]) {
					i++;
				}
			}
		}
		return false;
    }
};