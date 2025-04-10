#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, amax;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        amax = max(amax, a[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int b[101] = {0};
        int j = i, k = 1, sum = 0, len = n;
        while(1) {
            if(b[j] == 0) {
                if(k == a[j]) {
                    b[j] = 1;
                    sum += k;
                    ans = max(ans, sum);
                    k = 0;
                    len--;
                }
                k++;
            }
            if(k > amax || len == 0) {
                break;
            }
            j++;
            if(j == n + 1) {
                j = 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
