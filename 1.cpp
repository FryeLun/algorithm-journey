#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> a;
    for(int i = 2, tmp = 0; i <= sqrt(n); i++) {
        if(n % i == 0) {
            a.push_back(i);
        }
    }
    int cnt = 1, nmax = 0, index = 0;
    for(int i = 1; i < a.size(); i++) {
        if(a[i - 1]== a[i] - 1) {
            cnt++;
        } else {
            if(cnt > nmax) {
                nmax = cnt;
                index = i - cnt;
                cnt = 1;
            }
        }
    }
    cout << nmax << endl;
    for(int i = index; i < index + nmax; i++) {
        cout << a[i];
        if(i != index + nmax - 1) {
            cout << '*';
        }
    }
    return 0;
}