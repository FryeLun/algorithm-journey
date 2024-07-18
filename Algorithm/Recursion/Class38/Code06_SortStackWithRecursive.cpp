// 用递归函数排序栈
// 栈只提供push、pop、isEmpty三个方法
// 请完成无序栈的排序，要求排完序之后，从栈顶到栈底从小到大
// 只能使用栈提供的push、pop、isEmpty三个方法、以及递归函数
// 除此之外不能使用任何的容器，数组也不行
// 就是排序过程中只能用：
// 1) 栈提供的push、pop、isEmpty三个方法
// 2) 递归函数，并且返回值最多为单个整数

#include <bits/stdc++.h>
using namespace std;

class SortStack {
public:
    void sort(stack<int>& stk) {
        int d = deep(stk);
        while (d > 0) {
            int m = max(stk, d);
            int k = times(stk, d, m);
            down(stk, d, m, k);
            d -= k;
        }
    }

    int deep(stack<int>& stk) {
        if (stk.empty()) {
            return 0;
        }
        int num = stk.top();
        stk.pop();
        int d = deep(stk) + 1;
        stk.push(num);
        return d;
    }

    int max(stack<int>& stk, int d) {
        if (d == 0) {
            return INT_MIN;
        }
        int num = stk.top();
        stk.pop();
        int restMax = max(stk, d - 1);
        int max = num < restMax ? restMax : num;
        stk.push(num);
        return max;
    }

    int times(stack<int>& stk, int d, int max) {
        if (d == 0) {
            return 0;
        }
        int num = stk.top();
        stk.pop();
        int restTimes = times(stk, d - 1, max);
        int times = restTimes + (num == max ? 1 : 0);
        stk.push(num);
        return times;
    }

    void down(stack<int>& stk, int d, int max, int k) {
        if (d == 0) {
            for (int i = 0; i < k; i++) {
                stk.push(max);
            }
        }
        else {
            int num = stk.top();
            stk.pop();
            down(stk, d - 1, max, k);
            if (num != max) {
                stk.push(num);
            }
        }
    }
};