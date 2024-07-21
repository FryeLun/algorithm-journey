// 含有嵌套的分子式求原子数量
// 测试链接 : https://leetcode.cn/problems/number-of-atoms/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int where;

    string countOfAtoms(string formula) {
        where = 0;
        map<string, int> m = f(formula, 0);
        string ans;
        for(auto& entry : m){
            ans += entry.first;
            if(entry.second > 1){
                ans += to_string(entry.second);
            }
        }
        return ans;
    }

    map<string, int> f(string& s, int i){
        map<string, int> ans;
        map<string, int> pre;
        string name;
        int cnt = 0;
        while(i < s.size() && s[i] != ')'){
            if(s[i] >= '0' && s[i] <= '9'){
                cnt = cnt * 10 + s[i++] -'0';
            }else if(s[i] >= 'A' && s[i] <= 'Z' || s[i] == '('){
                fillFormula(ans, name, pre, cnt);
                name.clear();
                pre.clear();
                cnt = 0;
                if(s[i] >= 'A' && s[i] <= 'Z'){
					name += s[i++];
				}else{
					pre = f(s, i + 1);
					i = where + 1;
				}
            }else{
                name += s[i++];
            }
        }
        fillFormula(ans, name, pre, cnt);
        where = i;
        return ans;
    }

    void fillFormula(map<string, int>& ans,string& name, map<string, int>& pre,int cnt){
        if(!name.empty() || !pre.empty()){
            cnt = cnt == 0 ? 1 : cnt;
            if (!name.empty()) {
                ans[name] += cnt;
            } else {
                for (auto& key : pre) {
                    ans[key.first] += key.second * cnt;
                }
            }
        }
    }
};