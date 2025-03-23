// 测试链接 : https://www.luogu.com.cn/problem/P4779

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXM = 2e5 + 5;
const int MAXN = 1e5 + 5;

struct Edge {
    int next, to, w;
}edge[MAXM];

int n, m, s;
int head[MAXM], cnt;
int dis[MAXN];
bool vis[MAXN];

struct node{
    int p, dis;
    bool operator <( const node &x )const{
        return x.dis < dis;
    };
};

priority_queue<node> h;

void add_edge(int u, int v, int w) {
    cnt++;
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    head[u] = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    for(int i = 1; i <= m ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[s] = 0;
    h.push((node){s, 0});
    while(!h.empty()) {
        node tmp = h.top();
        h.pop();
        int u = tmp.p;
        if(vis[u]) {
            continue;
        }
        vis[u] = true;
        for(int i = head[u]; i; i = edge[i].next) {
            int v = edge[i].to;
            if(dis[v] > dis[u] + edge[i].w) {
                dis[v] = dis[u] + edge[i].w;
                if(!vis[v]) {
                    h.push((node){v, dis[v]});
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    return 0;
}
