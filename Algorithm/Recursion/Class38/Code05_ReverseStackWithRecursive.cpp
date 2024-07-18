// 用递归函数逆序栈

#include <bits/stdc++.h>
using namespace std;

class ReverseStack {
public:
    void reverse(stack<int>& stk) {
        if (stk.empty()) {
            return;
        }
        int num = bottomOut(stk);
        reverse(stk);
        stk.push(num);
    }
    int bottomOut(stack<int>& stk) {
        int ans = stk.top();
        stk.pop();
        if (stk.empty()) {
            return ans;
        }
        else {
            int last = bottomOut(stk);
            stk.push(ans);
            return last;
        }
    }
};