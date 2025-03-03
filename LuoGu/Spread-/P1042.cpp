#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6;
int win[MAXN] = {0};

void f(int n) {
    int w = 0, l = 0;
    for(int i = 0; win[i] != 0; i++) {
        if(win[i] == 1) {
            w++;
        } else {
            l++;
        }
        if((w >= n || l >= n) && abs(w - l) >= 2) {
            cout << w << ":" << l << endl;
            w = 0;
            l = 0;
        }
    }
    cout << w << ":" << l << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char c;
    int cnt = 0;
    while(cin >> c && c != 'E') {
        win[cnt++] = c == 'W' ? 1 : 2;
    }
    f(11);
    cout << endl;
    f(21);
    return 0;
}
