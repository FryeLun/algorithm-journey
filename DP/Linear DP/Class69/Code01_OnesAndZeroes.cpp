// 一和零(多维费用背包)
// 给你一个二进制字符串数组 strs 和两个整数 m 和 n
// 请你找出并返回 strs 的最大子集的长度
// 该子集中 最多 有 m 个 0 和 n 个 1
// 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集
// 测试链接 : https://leetcode.cn/problems/ones-and-zeroes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int zeros = 0, ones = 0;

    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for(int i = len - 1; i >= 0; i--){
            zerosAndOnes(strs[i]);
            for(int z = 0, p1, p2; z <= m; z++){
                for(int o = 0; o <= n; o++){
                    p1 = dp[i + 1][z][o];
                    p2 = 0;
                    if(zeros <= z && ones <= o){
                        p2 = dp[i + 1][z - zeros][o - ones] + 1;
                    }
                    dp[i][z][o] = max(p1, p2);
                }
            }
        }
        return dp[0][m][n];
    }

    void zerosAndOnes(string s){
        zeros = 0;
		ones = 0;
        for(char c : s){
            if(c == '0'){
                zeros++;
            }else{
                ones++;
            }
        }
    }
};