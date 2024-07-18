// 打印n层汉诺塔问题的最优移动轨迹
#include <bits/stdc++.h>
using namespace std;

class TowerOfHanoi {
public:
    void hanoi(int n) {
        if (n > 0) {
            f(n, "左", "右", "中");
        }
    }

    void f(int n, string from, string to, string other) {
        if (n == 1) {
            cout << "移动圆盘1从" << from << "到" << to << endl;
        }
        else {
            f(n - 1, from, other, to);
            cout << "移动圆盘" << n << "从" << from << "到" << to << endl;
            f(n - 1, other, to, from);
        }
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    TowerOfHanoi Hanoi;
    Hanoi.hanoi(n);
}