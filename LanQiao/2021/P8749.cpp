#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

ll c(int a, int b) {
    ll ans = 1;
    for(int i = a, j = 1; j <= b; i--, j++) {
        ans = ans * i / j;
        if(ans > n) {
            return ans;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    return 0;
}
