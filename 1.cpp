#include <bits/stdc++.h>
using namespace std;
using ll = long long;

typedef tuple<int, int, int> p;
queue<p> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int cx, cy;
    cx = cy = 0;
    int d = 1;
    int dd{};

    for (int i = 0; i < n; i++)
    {

        int sz = q.size();
        if (s[i] == 'F')
            dd = 0;
        else if (s[i] == 'L')
            dd = -1;
        else
            dd = 1;

        for (int j = 0; j < sz; j++)
        {
            auto [a, b, c] = q.front();
            q.pop();
            q.emplace(a + dx[(c + dd + 4) % 4], b + dy[(c + dd + 4) % 4], (c + dd + 4) % 4);
        }

        for (int k = -1; k <= 1; k++)
        {
            if (k == dd)
                continue;
            q.emplace(cx + dx[(k + d + 4) % 4], cy + dy[(k + d + 4) % 4], (k + d + 4) % 4); // 一直不变的坐标加上改变方向的操作，并进入队列
        }

        d = (d + dd + 4) % 4;
        cx += dx[d];
        cy += dy[d];
    }

    set<pair<int, int>> ss;
    while (q.size())
    {
        auto [a, b, c] = q.front();
        q.pop();
        ss.insert(make_pair(a, b));
    } 

    cout << ss.size();
    return 0;
}