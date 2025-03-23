#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[10] = {13, 1, 2, 3, 5, 4, 4, 2, 2, 2};

bool f1(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int f2(int y, int m, int d) {
    int sum = a[y / 1000] + a[y / 100 % 10] + a[y / 10 % 10] + a[y % 10];
    if(m < 10) {
        sum += a[0] + a[m];
    }else{
        sum += a[m / 10] + a[m % 10];
    }
    if(d < 10) {
        sum += a[0] + a[d];
    } else {
        sum += a[d / 10] + a[d % 10];
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int day[12] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    // int ans = 0;
    // int y = 2000, m = 1, d = 1;
    // while(1) {
    //     if(f2(y, m , d) > 50){
    //         ans++;
    //     }
    //     if(f1(y)){
    //         day[2] = 29;
    //     } else {
    //         day[2] = 28;
    //     }
    //     if(m != 12 && day[m] == d) {
    //         m++;
    //         d = 1;
    //     } else if(m == 12 && d == 31) {
    //         y++;
    //         m = 1;
    //         d = 1;
    //     } else {
    //         d++;
    //     }
    //     if(y == 2024 && m == 4 && d == 13) {
    //         break;
    //     }
    // }
    // cout << ans << endl;
    cout << 3228 << endl;
    return 0;
}
