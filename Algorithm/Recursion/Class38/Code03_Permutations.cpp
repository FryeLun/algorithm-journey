// 没有重复项数字的全排列
// 测试链接 : https://leetcode.cn/problems/permutations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        f(nums, 0, ans);
        return ans;
    }

    //将nums数组作为路径
    void f(vector<int>& nums, int i, vector<vector<int>>& ans){
        if(i == nums.size()){
            vector<int> cur;
            for(int num : nums){
                cur.push_back(num);
            }
            ans.push_back(cur);
        }else{
            for(int j = i;j < nums.size();j++){
                swap(nums[i], nums[j]);
                f(nums, i + 1, ans);
                swap(nums[i], nums[j]);
            }
        }
    }
};