// 有效涂色问题
// 给定n、m两个参数
// 一共有n个格子，每个格子可以涂上一种颜色，颜色在m种里选
// 当涂满n个格子，并且m种颜色都使用了，叫一种有效方法
// 求一共有多少种有效的涂色方法
// 1 <= n, m <= 5000
// 结果比较大请 % 1000000007 之后返回
// 对数器验证

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    for(int i  = 1; i <= n; i++){
        dp[i][1] = m;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m ; j++){
            dp[i][j] = (int) (((ll) dp[i - 1][j] * j) % MOD);
			dp[i][j] = (int) ((((ll) dp[i - 1][j - 1] * (m - j + 1)) + dp[i][j]) % MOD);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}