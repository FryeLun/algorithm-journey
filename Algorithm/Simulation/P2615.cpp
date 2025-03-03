#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));
    int num = 1, x, y;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(num == 1) {
                x = 1, y = n / 2 + 1;
            } else if(x == 1 && y != n) {
                x = n, y += 1;
            } else if(x != 1 && y == n) {
                x -= 1, y = 1;
            } else if(x == 1 && y == n) {
                x += 1;
            } else if(x != 1 && y != n) {
                if (ans[x - 1][y + 1] == 0) {
                    x -= 1, y += 1;
                } else {
                    x += 1;
                }
            }
            ans[x][y] = num++;
        }
    } 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) { 
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
