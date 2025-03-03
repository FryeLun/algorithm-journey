#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[1005] = {0};
    for(int i = 0, num; i < n; i++) {
        cin >> num;
        a[num]++;
    }
    int cnt = 0;
    for(int i = 0; i < 1005; i++) {
        if(a[i] != 0) {
            cnt++;
        }
    }
    cout << cnt << endl;
    for(int i = 0; i < 1005; i++) {
        if(a[i] != 0) {
            cout << i << " ";
        }
    }    
    return 0;
}
