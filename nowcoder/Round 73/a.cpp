#include <iostream>
using namespace std;

int main() {
    int l, r, x;
    cin >> l >> r >> x;
    int ans = -1;
    for (int i = l; i <= r; i++) {
        if (i % x == 0) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}