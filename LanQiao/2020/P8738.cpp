#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string t[10]= {"geng", "xin", "ren", "gui", "jia", "yi", "bing", "ding", "wu", "ji"};
string d[12] = {"shen", "you", "xu", "hai", "zi", "chou", "yin", "mao", "chen", "si", "wu", "wei"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int y;
    cin >> y;
    cout << t[y % 10] << d[y % 12] << endl;
    return 0;
}
