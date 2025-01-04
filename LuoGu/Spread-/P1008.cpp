#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[10];

bool check () {
    for (int i = 1; i <= 9; i++) {
        if (a[i] != 1){
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // for (int i = 100; i < 333; i++) {
    //     memset(a, 0, sizeof(a));
    //     int ge = i % 10, shi = i % 100 / 10, bai = i / 100;
    //     if (ge != shi && ge != bai && shi != bai) {
    //         for (int j = 1; j <= 3; j++) {
    //             int temp = i * j;
    //             while (temp > 0) {
    //                 a[temp % 10]++;
    //                 temp /= 10;
    //             }
    //         }
    //         if (check()) {
    //             cout << i << " " << i * 2 << " " << i * 3 << endl;
    //         }
    //     }
    // }
    printf("192 384 576\n219 438 657\n273 546 819\n327 654 981");
    return 0;
}
