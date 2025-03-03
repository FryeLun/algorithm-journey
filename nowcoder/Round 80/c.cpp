#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<int> a(n + 1);
    a[0] = 0;
    int ans = 0;
    int win = 0, lose = 0;
    for(int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        if(c = 1) {
            win++;
        } else {
            lose++;
        }
        a[i] = win - lose;
    }
    for(int i = 1; i <= n; i++) {
        vector<int> temp = a;
        if()
        for(int j = 1; j <= n; j++) {
            if(temp[j] < 0) {
                break;
            }
        }
    }
    return 0;
}
