// 字符串的全部子序列
// 子序列本身是可以有重复的，只是这个题目要求去重
// 测试链接 : https://www.nowcoder.com/practice/92e6247998294f2c933906fdedbc6e6a

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generatePermutation(string s) {
        vector<string> ans;
        unordered_set<string> set;
        string path;
        f2(s, 0, path, 0, set);
        for(string cur : set){
            ans.push_back(cur);
        }
        return ans;
    }

    void f1(string& s, int i, string& path, unordered_set<string>& set){
        if(i == s.size()){
            set.emplace(path); 
        }else{
            path.push_back(s[i]);
            f1(s, i + 1, path, set);
            path.erase(path.end() - 1);
            f1(s, i + 1, path, set);
        }
    }

    void f2(string& s, int i, string& path, int size, unordered_set<string>& set){
        if(i == s.size()){
            set.emplace(string(path.begin(), path.begin() + size)); 
        }else{
            path[size] = s[i];
            f2(s, i + 1, path, size + 1, set);
            f2(s, i + 1, path, size, set);
        }
    }
};