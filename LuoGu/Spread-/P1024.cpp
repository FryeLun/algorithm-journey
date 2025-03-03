#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    for (double i = -100; i <= 100; i += 0.001) {
        double j = i + 0.001;
        double y1 = a * i * i * i + b * i * i + c * i + d;
        double y2 = a * j * j * j + b * j * j + c * j + d;
        if (y1 >= 0 && y2 <= 0 || y1 <= 0 && y2 >= 0) {
            double x = (i + j) / 2;
            printf("%.2lf ", x);
        }
    }
    return 0;
}
