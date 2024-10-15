// 最长回文子序列
// 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度
// 测试链接 : https://leetcode.cn/problems/longest-palindromic-subsequence/

#include <bits/stdc++.h>
using namespace std;

//将问题转化为lcs
class Solution1 {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2;
        for(int i = n - 1;i >= 0;i--){
            s2 += s[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(s[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
};

class Solution2 {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int l = n - 1;l >= 0;l--){
            dp[l][l] = 1;
            if(l + 1 < n){
				dp[l][l + 1] = s[l] == s[l + 1] ? 2 : 1;
			}
            for(int r = l + 2;r < n;r++){
                if(s[l] == s[r]){
                    dp[l][r] = dp[l + 1][r - 1] + 2;
                }else{
                    dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};