#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 505;

struct edge {
    int next, to, w;
}e[MAX];

int n, m, s, d, cnt;
int head[MAX], dis[MAX], jiu[MAX];
bool vis[MAX];

struct node{
    int p, dis;
    bool operator < (const node &x) const {
        return x.dis < dis;
    }
};

void add_edge(int u, int v, int w) {
    e[cnt].next = head[u];
    e[cnt].to = v;
    e[cnt].w = w;
    head[u] = cnt++;
}

void dijkstra() {
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[s] = 0;
    priority_queue<node> h;
    h.push((node{s, 0}));
    while(!h.empty()) {
        node tmp = h.top();
        h.pop();
        int u = tmp.p, w = tmp.dis;
        if(vis[u]) {
            continue;
        };
        vis[u] = true;
        for(int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            if(dis[v] > dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
                if(!vis[v]) {
                    h.push((node){v, dis[v]});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> d;
    for(int i = 0; i < n; i++) {
        cin >> jiu[i];
    }
    for(int i = 0; i < m; i++) {
        int u, v , w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    return 0;
}
