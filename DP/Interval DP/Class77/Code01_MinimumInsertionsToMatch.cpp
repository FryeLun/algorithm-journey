// 完成配对需要的最少字符数量
// 给定一个由'['、']'、'('，')'组成的字符串
// 请问最少插入多少个括号就能使这个字符串的所有括号正确配对
// 例如当前串是 "([[])"，那么插入一个']'即可满足
// 输出最少需要插入多少个字符
// 测试链接 : https://www.nowcoder.com/practice/e391767d80d942d29e6095a935a5b96b

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[n - 1][n - 1] = 1;
    for (int i = 0; i < n - 1; i++) {
        dp[i][i] = 1;
        dp[i][i + 1] = (s[i] == '(' && s[i + 1] == ')') || (s[i] == '[' && s[i + 1] == ']') ? 0 : 2;
    }
    for (int l = n - 3; l >= 0; l--) {
        for (int r = l + 2; r < n; r++) {
            dp[l][r] = INT_MAX;
            if ((s[l] == '(' && s[r] == ')') || (s[l] == '[' && s[r] == ']')) {
                dp[l][r] = dp[l + 1][r - 1];
            }
            for (int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}