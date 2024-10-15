// 编辑距离
// 给你两个单词 word1 和 word2
// 请返回将 word1 转换成 word2 所使用的最少代价
// 你可以对一个单词进行如下三种操作：
// 插入一个字符，代价a
// 删除一个字符，代价b
// 替换一个字符，代价c
// 测试链接 : https://leetcode.cn/problems/edit-distance/

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int minDistance(string word1, string word2) {
        return editDistance(word1, word2, 1, 1, 1);
    }

    int editDistance(string& word1, string& word2, int a, int b, int c){
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 1;i <= n;i++){
            dp[i][0] = i * b;
        }
        for(int j = 1;j <= m;j++){
            dp[0][j] = j * a;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                int p1 = 0x3f3f3f3f;
                if(word1[i - 1] == word2[j - 1]){
                    p1 = dp[i - 1][j - 1];
                }
                int p2 = 0x3f3f3f3f;
                if(word1[i - 1] != word2[j - 1]){
                    p1 = dp[i - 1][j - 1] + c;
                }
                int p3 = dp[i][j - 1] + a;
                int p4 = dp[i - 1][j] + b;
                dp[i][j] = min(min(p1, p2), min(p3, p4));
            }
        }
        return dp[n][m];
    }
};

class Solution2 {
public:
    int minDistance(string word1, string word2) {
        return editDistance(word1, word2, 1, 1, 1);
    }

    int editDistance(string& word1, string& word2, int a, int b, int c){
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 1;i <= n;i++){
            dp[i][0] = i * b;
        }
        for(int j = 1;j <= m;j++){
            dp[0][j] = j * a;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    dp[i][j] = min(min(dp[i - 1][j] + b, dp[i][j - 1] + a), dp[i - 1][j - 1] + c);
                }
            }
        }
        return dp[n][m];
    }
};