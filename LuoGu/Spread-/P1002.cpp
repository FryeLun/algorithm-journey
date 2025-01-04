#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int bx, by, mx, my;
const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool m[21][21];
ll dp[21][21];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> bx >> by >> mx >> my;
    m[mx][my] = true;
    for (int i = 0; i < 8; i ++) {
        int dmx = mx + dx[i];
        int dmy = my + dy[i];
        if(dmx >= 0 && dmy >= 0 && dmx <= bx && dmy <= by) {
            m[dmx][dmy] = true;
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i <= bx; i++) {
        for ( int j = 0; j <= by; j++) {
            if (m[i][j] == false) {
                if(i - 1 >= 0) dp[i][j] = dp[i - 1][j] + dp[i][j];
                if(j - 1 >= 0) dp[i][j] = dp[i][j - 1] + dp[i][j];
            }
        }
    }
    cout << dp[bx][by] << endl;
    return 0;
}
