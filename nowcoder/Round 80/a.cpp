#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x, y;
    cin >> x >> y;
    if(x >= y) {
        cout << x - y << endl;
    } else {
        cout << "quit the competition!" << endl;
    }
    return 0;
}
