// 有重复项数组的去重全排列
// 测试链接 : https://leetcode.cn/problems/permutations-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        f(nums, 0, ans);
        return ans;
    }

    void f(vector<int>& nums, int i, vector<vector<int>>& ans){
        if(i == nums.size()){
            vector<int> cur;
            for(int num : nums){
                cur.push_back(num);
            }
            ans.push_back(cur);
        }else{
            unordered_set<int> set;
            for(int j = i;j < nums.size();j++){
                if (set.find(nums[j]) == set.end()){
                    set.emplace(nums[j]);
                    swap(nums[i], nums[j]);
                    f(nums, i + 1, ans);
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
};