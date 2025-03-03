#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;

int f(int num, int i, int cnt) {
    if(cnt == 1) {
        return 1;
    }
    int sum = 0;
    for(int j = i; j <= num / cnt; j++) {
        sum += f(num - j, j, cnt - 1);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    cout << f(n, 1, k) << endl;
    return 0;
}
