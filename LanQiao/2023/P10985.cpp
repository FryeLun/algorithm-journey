#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(int a) {
    int sum = 0;
    while(a) {
        sum += a % 10;
        a /= 10; 
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    while(n) {
        n -= f(n);
        ans++;
    }
    cout << ans << endl;
    return 0;
}
