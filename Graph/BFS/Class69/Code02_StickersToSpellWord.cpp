#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        vector<string> q(401);
        int l, r;
        vector<vector<string>> graph(26);
        unordered_set<string> visited;
        for (auto& str : stickers) {
            sort(str.begin(), str.end());
            for (int i = 0; i < str.size(); i++) {
                if (i == 0 || str[i] != str[i - 1]) {
                    graph[str[i] - 'a'].push_back(str);
                }
            }
        }
        sort(target.begin(), target.end());
        visited.insert(target);
        l = r = 0;
        q[r++] = target;
        int level = 1;
        while (l < r) {
            int size = r - l;
            for (int i = 0; i < size; i++) {
                string cur = q[l++];
                for (string s : graph[cur[0] - 'a']) {
                    string next = getNext(cur, s);
                    if (next.empty()) {
                        return level;
                    }
                    else if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q[r++] = next;
                    }
                }
            }
            level++;
        }
        return -1;
    }

    string getNext(string& target, string& sticker) {
        string result;
        int i = 0, j = 0;
        while (i < target.length()) {
            if (j == sticker.length()) {
                result += target[i++];
            }
            else {
                if (target[i] < sticker[j]) {
                    result += target[i++];
                }
                else if (target[i] > sticker[j]) {
                    j++;
                }
                else {
                    i++;
                    j++;
                }
            }
        }
        return result;
    }
};