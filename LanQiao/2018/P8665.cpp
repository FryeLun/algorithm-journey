#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(){
    int h1, h2, m1, m2, s1, s2;
    scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
    int day = 0;
    if(getchar() == ' '){
        scanf("(+%d)", &day);
    }
    int sum1 = h1 * 3600 + m1 * 60 + s1;
    int sum2 = day * 24 * 3600 + h2 * 3600 + m2 * 60 + s2;
    return sum2 - sum1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    scanf("%d", &t);
    while(t--) {
        int ans = f() + f();
        ans /= 2;
        int h = ans / 3600, m = ans % 3600 / 60, s = ans % 60;
        printf("%02d:%02d:%02d\n", h, m, s);
    }
    return 0;
}
