// 丑数 II
// 给你一个整数 n ，请你找出并返回第 n 个 丑数
// 丑数 就是只包含质因数 2、3 或 5 的正整数
// 测试链接 : https://leetcode.cn/problems/ugly-number-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for(int i = 2, ia = 1, ib = 1, ic = 1, a, b, c, cur;i <= n;i++){
            a = dp[ia] * 2;
            b = dp[ib] * 3;
            c = dp[ic] * 5;
            cur = min(min(a, b), c);
            if(cur == a) ia++;
            if(cur == b) ib++;
            if(cur == c) ic++;
            dp[i] = cur;
        }
        return dp[n];
    }
};