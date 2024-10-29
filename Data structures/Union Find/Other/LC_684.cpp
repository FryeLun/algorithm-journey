#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const static int MAXN = 1001;
    int father[MAXN];
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        build(n);
        for (auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            if (isSameSet(node1, node2)){
                return edge;
            } else {
                unionSets(node1, node2);
            }
        }
        return vector<int>{};
    }

    void build(int n) {
        for (int i = 0; i <= n; i++) {
            father[i] = i;
        }
    }

    int find(int i) {
        if (i != father[i]) {
            father[i] = find(father[i]);
        }
        return father[i];
    }

    bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }

    void unionSets(int x, int y) {
        father[find(x)] = find(y);
    }
};