#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static const int MAXN = 1001;
    int father[MAXN];
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> edge1, edge2;
        for (auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            if (father[node2] == 0) {
                father[node2] = node1;
            } else {
                edge1 = {father[node2], node2};
                edge2 = {node1, node2};
                edge = {-1, -1};
            }
        }
        
        build(n + 1);
        for (auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            if (node1 == -1 && node2 == -1) {
                continue;
            }
            if (isSameSet(node1, node2)) {
                if (!edge1.empty()) {
                    return edge1;
                } else {
                    return edge;
                }
            } else {
                unionSets(node1, node2);
            }
        }

        if (!edge2.empty()) {
            return edge2;
        }

        return vector<int>{};
    }

    void build(int n) {
        for (int i = 0; i < n; i++) {
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