#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int layer;
    while (n > layer) {
        n -= layer;
        layer++;
    }
    if (layer % 2 == 0) {
        cout << n << "/" << layer + 1 - n << endl;
    } else {
        cout << layer + 1 - n << "/" << n << endl;
    }
    return 0;
}
