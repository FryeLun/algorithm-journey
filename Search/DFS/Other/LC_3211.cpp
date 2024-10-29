#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string path(n, 0);
        auto dfs = [&](auto&& dfs, int i) -> void {
            if (i == n) {
                ans.push_back(path);
                return;
            }
            path[i] = '1';
            dfs(dfs, i + 1);
            if (i == 0 || path[i - 1] == '1') {
                path[i] = '0';
                dfs(dfs, i + 1);
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};