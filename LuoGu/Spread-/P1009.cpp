#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[1001] = {0}, b[1001] = {0};
    a[0] = b[0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 1000; j++) {
            a[j] *= i;
        }
        for (int j = 0; j < 1000; j++) {
            if (a[j] > 9) {
                a[j + 1] += a[j] / 10;
                a[j] %= 10;
            }
            b[j] += a[j];
            if (b[j] > 9) {
                b[j + 1] += b[j] / 10;
                b[j] %= 10;
            }
        }
    }
    int i;
    for (i = 1000; i >= 0 && b[i] == 0; i--);
    for (int j = i; j >= 0; j--) {
        cout << b[j];
    }
    return 0;
}