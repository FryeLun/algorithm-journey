// 含有嵌套的字符串解码
// 测试链接 : https://leetcode.cn/problems/decode-string/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int where = 0;

    string decodeString(string s) {
        where  = 0;
        return f(s, 0);
    }

    string f(string &s, int i){
        int num = 0;
        string ans;
        while(i < s.size() && s[i] != ']'){
            if(s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + s[i++] - '0';
            }else if(s[i] >= 'a' && s[i] <= 'z'){
                ans += s[i++];
            }else{
                ans += get(f(s, i + 1), num);
                i = where + 1;
                num = 0;
            }
        }
        where = i;
        return ans;
    }

    string get(string str, int n){
        string ans;
        for(int i = 0;i < n;i++){
            ans += str;
        }
        return ans;
    }
};