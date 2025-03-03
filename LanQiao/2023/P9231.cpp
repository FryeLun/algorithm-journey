#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // map<int, int> m;
    // for(int i = 1; i <= 100; i++){
    //     for(int j = 0; j <= 100 ; j++) {
    //         for(int k = 0; k <= 100; k++) {
    //             if(j * j - k * k == i) {
    //                 if(!m[i]){
    //                     cout << i << endl;
    //                 }
    //                 m[i]++;
    //             }
    //         }
    //     }
    // }
    int l, r;
    cin >> l >> r;
    int sl = (l - 1) / 4 + l / 2;
    int sr = r / 4 + (r + 1) / 2;
    cout << sr  - sl << endl;
    return 0;
}
