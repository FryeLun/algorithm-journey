//字符迁移
//测试链接：https://www.lanqiao.cn/problems/17164/learning/?contest_id=179

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<ll> a(n + 2, 0);
    while (q--)
    {
        int l, r, t;
        cin >> l >> r >> t;
        a[l] += t;
        a[r + 1] -= t;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        ll t = s[i - 1] - 'a' + a[i];
        t %= 26;
        s[i - 1] = t + 'a';
    }
    cout << s << endl;
    return 0;
}