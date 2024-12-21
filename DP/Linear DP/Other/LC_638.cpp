#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        vector<vector<int>> filterSpecial;
        map<vector<int>, int> dp;

        for (auto& pack : special) {
            int totalCount = 0;
            int totalPrice = 0;
            int packPrice = pack[n];
            for (int i = 0; i < n; i++) {
                totalCount += pack[i];
                totalPrice += pack[i] * price[i];
            }
            if (totalCount > 0 && totalPrice > packPrice) {
                filterSpecial.push_back(pack);
            }
        }

        auto dfs = [&](auto&& dfs, vector<int>& curNeeds) -> int {
            if (dp.count(curNeeds)) {
                return dp[curNeeds];
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans += price[i] * curNeeds[i];
            }
            for (auto& curSpecial : filterSpecial) {
                int specialPrice = curSpecial[n];
                vector<int> nextNeed(n);
                bool validOffer = true;

                for (int i = 0; i < n; i++) {
                    if (curSpecial[i] > curNeeds[i]) {
                        validOffer = false;
                        break;
                    }
                    nextNeed[i] = curNeeds[i] - curSpecial[i];
                }

                if (validOffer) {
                    ans = min(ans, dfs(dfs, nextNeed) + specialPrice);
                }
            }

            dp[curNeeds] = ans;
            return ans;
        };

        return dfs(dfs, needs);
    }
};
