#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    double w, p;
    bool operator < (const node &x) const{
        return p / w > x.p / x.w;
    }
}goods[1005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n, aim;
    cin >> n >> aim;
    double ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> goods[i].w;
    }
    for(int i = 0; i < n; i++) {
        cin >> goods[i].p;
    }
    sort(goods, goods + n);
    for(int i = 0;i < n; i++) {
        if(goods[i].w >= aim) {
            ans += (double)goods[i].p / goods[i].w * aim;
            break;
        } else {
            ans += goods[i].p;
            aim -= goods[i].w;
        }
    }
    
    printf("%.2lf", ans);
	return 0;
}