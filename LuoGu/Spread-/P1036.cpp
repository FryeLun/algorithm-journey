#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int num[22];
int ans;

bool isprime(int a) {
    if(a == 1) {
        return false;
    }
    for(int i = 2; i <= sqrt(a); i++) {
        if(a % i == 0) {
            return false;
        }
    }
    return true;
}

void f(int i, int cnt, int sum) {
    if(cnt == k) {
        if(isprime(sum)){
            ans++;
        }
        return;
    }
    for(int j = i; j < n; j++) {
        f(j + 1, cnt + 1, sum + num[j]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    ans = 0;
    f(0, 0, 0);
    cout << ans << endl;
    return 0;
}
