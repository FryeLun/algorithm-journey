#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int cnt = 0, time = 0;
        int mm[1010][10];
        int book;
        char c;
        while (1) {
            int h, m;
            cin >> book >> c >> h;
            getchar();
            cin >> m;
            if (book == 0) {
                break;
            }
            if (c == 'S') {
                mm[book][0] = book;
                mm[book][1] = 1;
                mm[book][2] = h;
                mm[book][3] = m;
                continue;
            }
            if (c == 'E' && mm[book][1] == 1) {
                time += h * 60 + m - mm[book][2] * 60 - mm[book][3];
                mm[book][1] = 0;
                cnt++;
            }
        }
        if (cnt == 0) {
            cout << 0 << " " << 0 << endl;
        } else {
            cout << cnt << " " << (time + cnt - 1) / cnt << endl;
        }
    }
    return 0;
}