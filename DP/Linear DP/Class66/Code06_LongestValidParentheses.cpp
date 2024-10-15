// 最长有效括号
// 给你一个只包含 '(' 和 ')' 的字符串
// 找出最长有效（格式正确且连续）括号子串的长度。
// 测试链接 : https://leetcode.cn/problems/longest-valid-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        int ans = 0;
        for(int i = 1, p;i < s.size();i++){
            if(s[i] == ')'){
                p = i - dp[i - 1] - 1;
                if(p >= 0 && s[p] == '('){
					dp[i] = dp[i - 1] + 2 + (p - 1 >= 0 ? dp[p - 1] : 0);
				}
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};