#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
int n, m;
int cnt[N];
vector<int> v[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0, num; i < n; i++) {
        cin >> num;
        cnt[num]++;
        m = max(m, num);
    }
    for(int i = 1; i <= m; i++) {
        for(int j = i; j <= m; j += i) {
            if(cnt[j]) {
                for(int k = 0; k < cnt[j]; k++) {
                    v[i].push_back(j);
                }
            }
        }
    }
    for (int i = m; i >= 1; i--){
        if(v[i].size() >= 3){
            sort(v[i].begin(), v[i].end());
            for(int j = 0; j < 3; j++) cout << v[i][j] << ' ';
            break;
        }
    }
    return 0;
}
