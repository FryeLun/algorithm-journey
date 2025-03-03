#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string nmax;
    int bmax = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        string name;
        char a, b;
        int grade1, grade2, cnt;
        int bonus = 0;
        cin >> name >> grade1 >> grade2 >> a >> b >> cnt;
        if(grade1 > 80 && cnt >= 1) {
            bonus += 8000;
        }
        if(grade1 > 85 && grade2 > 80) {
            bonus += 4000;
        }
        if(grade1 > 90) {
            bonus += 2000;
        }
        if(grade1 > 85 && b == 'Y') {
            bonus += 1000;
        }
        if(grade2 > 80 && a == 'Y') {
            bonus += 850;
        }
        sum += bonus;
        if(bonus > bmax) {
            nmax = name;
            bmax = bonus;
        }
    }
    cout << nmax << endl;
    cout << bmax << endl;
    cout << sum << endl;
    return 0;
}
