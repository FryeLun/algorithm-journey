#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
int h, n;
int ans1[MAXN], ans2[MAXN];
int a1, a2;

struct Node{
    int k;
    int next;
}l[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> h >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cin >> l[a].k >> l[a].next; 
    }
    vector<int> cnt(100005);
    while(h != -1) {
        if(cnt[abs(l[h].k)]) {
            ans2[a2++] = h;
            h = l[h].next;
            ans2[a2] = -1; 
        } else {
            cnt[abs(l[h].k)] = 1;
            ans1[a1++] = h;
            h = l[h].next;
            ans1[a1] = -1; 
        }
    }
    for(int i = 0; i < a1; i++) {
        if(ans1[i + 1] != -1) {
            printf("%05d %d %05d\n", ans1[i], l[ans1[i]].k, ans1[i + 1]);
        } else {
            printf("%05d %d %d\n", ans1[i], l[ans1[i]].k, ans1[i + 1]);
        }
    }
    for(int i = 0; i < a2; i++) {
        if(ans2[i + 1] != -1) {
            printf("%05d %d %05d\n", ans2[i], l[ans2[i]].k, ans2[i + 1]);
        } else {
            printf("%05d %d %d\n", ans2[i], l[ans2[i]].k, ans2[i + 1]);
        }
    }
    return 0;
}
