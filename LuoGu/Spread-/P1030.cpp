#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void f(string in, string post) {
    if(in.size() > 0) {
        char c = post[post.size() - 1];
        cout << c;
        int k = in.find(c);
        f(in.substr(0, k), post.substr(0, k));
        f(in.substr(k + 1), post.substr(k, post.size() - k - 1));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string inorder, postorder;
    cin >> inorder >> postorder;
    f(inorder, postorder);
    return 0;
}
