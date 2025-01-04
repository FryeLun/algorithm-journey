#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 105;
char num[17] = "0123456789ABCDEF";

bool f (string a) {
    string b = a;
    reverse(b.begin(), b.end());
    return a == b;
}

string add (int n, string a) {
    string b = a;
    reverse(b.begin(), b.end());
    int numa[MAXN] = {0}, numb[MAXN] = {0};
    for (int i = 0; i <= a.size(); i++) {
        if (a[i] >= '0' && a[i] <= '9') {
            numa[i] = a[i] - '0';
        }
        if (b[i] >= '0' && b[i] <= '9') {
            numb[i] = b[i] - '0';
        }
        if (a[i] >= 'A' && a[i] <= 'F') {
            numa[i] = a[i] - 'A' + 10;
        }
        if (b[i] >= 'A' && b[i] <= 'F') {
            numb[i] = b[i] - 'A' + 10;
        }
    }
    string ans;
    for (int i = 0, temp = 0; i < a.size(); i++) {
        numa[i] += numb[i];
        temp = numa[i] / n;
        numa[i] %= n;
        numa[i + 1] += temp;
        ans += num[numa[i]];
    }
    if (numa[a.size()] != 0) ans += num[numa[a.size()]];
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string m;
    cin >> n >> m;
    for (int i = 0; i <= 30; i++) {
        if (f(m)) {
            cout << "STEP=" << i << endl;
            return 0;
        } else {
            m = add(n, m);
        }
    }
    cout << "Impossible!" << endl;
    return 0;
}
