#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[10005][2];
int n;

bool f(int m) {
    for(int i = 0; i < n; i++) {
        if(a[i][0] / m != a[i][1]){
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int amax = 1e9;
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
        amax = min(amax, a[i][0] / a[i][1]);
    }
    int l = 1, r = amax;
    while(l < r) {
        int mid = (l + r) / 2;
        if(f(mid)){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << " " << amax << endl;
    return 0;
}
