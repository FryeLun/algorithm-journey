#include <bits/stdc++.h>
using namespace std;

bool f(int n) {
    string s = to_string(n);
    int len = s.size();
    vector<int> a;
    for (int i = 0; i < len; i++) {
        a.push_back(s[i] - '0');
    }
    int where = 0;
    while (true) {
        int sum = 0;
        for (int i = a.size() - len; i < a.size(); i++) {
            sum += a[i];
        }
        if (sum == n) {
            return true;
        } else if (sum > n) {
            return false;
        }
        a.push_back(sum);
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// for(int i = 10000000; i >= 0; i--) {
	// 	if(f(i)){
	// 		cout << i << endl;
	// 		break;
	// 	}
	// }
    cout << 7913837 << endl;
	return 0;
}