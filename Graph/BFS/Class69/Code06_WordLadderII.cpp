// 单词接龙 II
// 按字典 wordList 完成从单词 beginWord 到单词 endWord 转化
// 一个表示此过程的 转换序列 是形式上像 
// beginWord -> s1 -> s2 -> ... -> sk 这样的单词序列，并满足：
// 每对相邻的单词之间仅有单个字母不同
// 转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词
// 注意，beginWord 不必是字典 wordList 中的单词
// sk == endWord
// 给你两个单词 beginWord 和 endWord ，以及一个字典 wordList
// 请你找出并返回所有从 beginWord 到 endWord 的 最短转换序列
// 如果不存在这样的转换序列，返回一个空列表
// 每个序列都应该以单词列表 [beginWord, s1, s2, ..., sk] 的形式返回
// 测试链接 : https://leetcode.cn/problems/word-ladder-ii/

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include<string>
using namespace std;

class Solution {
private:
    unordered_set<string> dict;
    unordered_set<string> curLevel;
    unordered_set<string> nextLevel;
    unordered_map<string, vector<string>> graph;
    list<string> path;
    vector<vector<string>> ans;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        build(wordList);
        if (dict.find(endWord) == dict.end()) {
            return ans;
        }
        if (bfs(beginWord, endWord)) {
            dfs(endWord, beginWord);
        }
        return ans;
    }

    void build(vector<string>& wordList) {
        dict = unordered_set<string>(wordList.begin(), wordList.end());
        graph.clear();
        ans.clear();
        curLevel.clear();
        nextLevel.clear();
    }

    bool bfs(string& begin, string& end) {
        bool find = false;
        curLevel.insert(begin);
        while (!curLevel.empty()) {
            for (string word : curLevel) {
                dict.erase(word);
            }
            for (string word : curLevel) {
                string tmp = word;
                for (int i = 0; i < word.size(); i++) {
                    char old = tmp[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        tmp[i] = ch;
                        string str = tmp;
                        if (dict.find(str) != dict.end() && str != word) {
                            if (str == end) {
                                find = true;
                            }
                            graph[str].push_back(word);
                            if (nextLevel.find(str) == nextLevel.end()) {
                                nextLevel.insert(str);
                            }
                        }
                    }
                    tmp[i] = old;
                }
            }
            if (find) {
                return true;
            }
            else {
                unordered_set<string> tmp = curLevel;
                curLevel = nextLevel;
                nextLevel = tmp;
                nextLevel.clear();
            }
        }
        return false;
    }

    void dfs(string word, string aim) {
        path.push_front(word);
        if (word == aim) {
            ans.push_back(vector<string>(path.begin(), path.end()));
        }
        else if (graph.find(word) != graph.end()) {
            for (string next : graph[word]) {
                dfs(next, aim);
            }
        }
        path.pop_front();
    }
};