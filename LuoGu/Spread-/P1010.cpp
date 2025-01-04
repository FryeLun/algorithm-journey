#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void f(int x) {
    for (int i = (int)log2(x); i >= 0; i--) {
        if (pow(2, i) <= x) {
            if (i == 1) {
                cout << 2;
            } else if (i == 0) {
                cout << "2(0)";
            } else {
                cout << "2(";
                f(i);
                cout << ")";
            }
            x -= pow(2, i);
            if (x != 0) {
                cout << "+";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    f(n);
    return 0;
}
