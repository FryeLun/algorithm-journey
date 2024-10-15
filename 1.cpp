#include <bits/stdc++.h>
using namespace std;

bool is_zf(int s){
    int a = sqrt(s);
    return a * a == s;
}

bool is_db(int s){
    int a = sqrt(4 * s / sqrt(3));
    return a * (a + 1) == (4 * s) / sqrt(3);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int s;
        cin >> s;
        bool zf = is_zf(s), db = is_db(s);
        if(zf && db){
            cout << 2 << endl;
        }else if(zf){
            cout << 0 << endl;
        }else if(db){
            cout << 1 << endl;
        }else{
            cout << 3 << endl;
        }
    }
    return 0;
}
