// 斐波那契数
// 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列
// 该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
// 也就是：F(0) = 0，F(1) = 1
// F(n) = F(n - 1) + F(n - 2)，其中 n > 1
// 给定 n ，请计算 F(n)
// 测试链接 : https://leetcode.cn/problems/fibonacci-number/
// 注意：最优解来自矩阵快速幂，时间复杂度可以做到O(log n)

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int dp[31];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2;i <= n;i++){
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};

//状态压缩
class Solution2 {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int a = 0, b = 1;
        int cur;
        for(int i = 2;i <= n;i++){
            cur = a + b;
            a = b;
            b = cur;
        }
        return b;
    }
};