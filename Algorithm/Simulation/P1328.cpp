#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int check[5][5] = {
	{0, -1, 1, 1, -1},
	{1, 0, -1, 1, -1},
	{-1, 1, 0, -1, 1},
	{-1, -1, 1, 0, 1},
	{1, 1, -1, -1, 0}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> na(a);
    vector<int> nb(b);
    for(int i = 0; i < a; i++) {
        cin >> na[i];
    }
    for(int i = 0; i < b; i++) {
        cin >> nb[i];
    }
    int scoreA = 0, scoreB = 0;
    for(int i = 0, ia = 0, ib = 0;i < n; i++, ia++, ib++) {
        if(ia == a){
            ia = 0;
        }
        if(ib == b){
            ib = 0;
        }
        int flag = check[na[ia]][nb[ib]];
        if(flag == 1) {
            scoreA++;
        } else if(flag == -1) {
            scoreB++;
        }
    }
    cout << scoreA << " " << scoreB << endl;
    return 0;
}
