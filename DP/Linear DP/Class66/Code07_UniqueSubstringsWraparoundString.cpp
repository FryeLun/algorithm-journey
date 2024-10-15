// 环绕字符串中唯一的子字符串
// 定义字符串 base 为一个 "abcdefghijklmnopqrstuvwxyz" 无限环绕的字符串
// 所以 base 看起来是这样的：
// "..zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd.."
// 给你一个字符串 s ，请你统计并返回 s 中有多少 不同非空子串 也在 base 中出现
// 测试链接 : https://leetcode.cn/problems/unique-substrings-in-wraparound-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> dp(26, 0);
        int ans = 0;
        dp[s[0] - 'a'] = 1;
        for(int i = 1, len = 1;i < s.size();i++){
            if((s[i - 1] == 'z' && s[i] == 'a') || (s[i - 1] + 1 == s[i])){
                len++;
            }else{
                len = 1;
            }
            dp[s[i] - 'a'] = max(dp[s[i] - 'a'], len);
        }
        for(int i = 0;i < 26;i++){
           ans += dp[i];
        }
        return ans;
    }
};