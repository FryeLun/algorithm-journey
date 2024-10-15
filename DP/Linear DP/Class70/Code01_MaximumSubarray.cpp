// 子数组最大累加和
// 给你一个整数数组 nums
// 返回非空子数组的最大累加和
// 测试链接 : https://leetcode.cn/problems/maximum-subarray/
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int ans = nums[0];
        for(int i = 1; i < n; i++){
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// 如下代码为附加问题的实现
// 子数组中找到拥有最大累加和的子数组
// 并返回如下三个信息:
// 1) 最大累加和子数组的开头left
// 2) 最大累加和子数组的结尾right
// 3) 最大累加和子数组的累加和sum
// 如果不止一个子数组拥有最大累加和，那么找到哪一个都可以

int left;
int right;
int sum;

class Extra{
public:
    int left;
    int right;
    int sum;

    void extra(vector<int>& nums){
        sum = INT_MIN;
        for(int l = 0, r = 0, pre = 0x3f3f3f3f; r < nums.size(); r++){
            if(pre >= 0){
                pre += nums[r];
            }else{
                pre = nums[r];
                l = r;
            }
            if(pre > sum){
                sum = pre;
                left = l;
                right = r;
            }
        }
    }
};