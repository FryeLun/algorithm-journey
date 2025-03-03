#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = n; i >= 0; i--) {
        int num;
        cin >> num;
        if(num) {
            if(i != n && num > 0) {
                cout << "+";
            }
            if(num < 0) {
                cout << "-";
            }
            num = abs(num);
            if(num != 1 || i == 0) {
                cout << num;
            }
            if(i > 1) {
                cout << "x^" << i;
            }
            if(i == 1) {
                cout << "x";
            }
        } 
    }
    return 0;
}
