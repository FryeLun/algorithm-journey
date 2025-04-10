#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string d;
int a[1000000];
int dot = 0, len = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d;
    reverse(d.begin(), d.end());
    dot = d.find('.');
    d.erase(dot, 1);
    len = d.size();
    for(int i = 0; i <len; i++) {
        a[i + 1] = d[i] - '0';
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= len; j++) {
            a[j] *= 2;
        }
        for(int j = 1; j <= len; j++) {
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
        }
        if(a[len + 1]) {
            len++;
        }
    }
    if(a[dot] >= 5) {
        a[dot + 1]++;
    }
    for(int i = dot + 1; i <= len; i++) {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    if(a[len + 1]) {
        len++;
    }
    for(int i = len; i > dot; i--) {
        cout << a[i];
    }
    return 0;
}
