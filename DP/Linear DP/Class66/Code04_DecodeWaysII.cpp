// 解码方法 II
// 一条包含字母 A-Z 的消息通过以下的方式进行了 编码 ：
// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// 要 解码 一条已编码的消息，所有的数字都必须分组
// 然后按原来的编码方案反向映射回字母（可能存在多种方式）
// 例如，"11106" 可以映射为："AAJF"、"KJF"
// 注意，像 (1 11 06) 这样的分组是无效的，"06"不可以映射为'F'
// 除了上面描述的数字字母映射方案，编码消息中可能包含 '*' 字符
// 可以表示从 '1' 到 '9' 的任一数字（不包括 '0'）
// 例如，"1*" 可以表示 "11"、"12"、"13"、"14"、"15"、"16"、"17"、"18" 或 "19"
// 对 "1*" 进行解码，相当于解码该字符串可以表示的任何编码消息
// 给你一个字符串 s ，由数字和 '*' 字符组成，返回 解码 该字符串的方法 数目
// 由于答案数目可能非常大，返回10^9 + 7的模
// 测试链接 : https://leetcode.cn/problems/decode-ways-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const static int MOD = 1e9 + 7;
    int numDecodings(string s) {
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        dp[n] = 1;
        for(int i = n - 1;i >= 0;i--){
            if(s[i] != '0'){
                dp[i] = (s[i] == '*' ? 9 : 1) * dp[i + 1];
                if(i + 1 < n){
                    if(s[i] != '*'){
                        if(s[i + 1] != '*'){
                            if((s[i] - '0') * 10 + s[i + 1] - '0' <= 26){
                                dp[i] += dp[i + 2];
                            }
                        }else{
                            if(s[i] == '1'){
                                dp[i] += 9 * dp[i + 2];
                            }
                            if(s[i] == '2'){
                                dp[i] += 6 * dp[i + 2];
                            }
                        }
                    }else{
                        if(s[i + 1] != '*'){
                            if(s[i + 1] <= '6'){
								dp[i] += dp[i + 2] * 2;
							}else{
								dp[i] += dp[i + 2];
							}
                        }else{
                            dp[i] += 15 * dp[i + 2];
                        }
                    }
                }
                dp[i] %= MOD;
            }
        }
        return (int)dp[0];
    }
};