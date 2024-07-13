// 到达首都的最少油耗
// 给你一棵 n 个节点的树（一个无向、连通、无环图）
// 每个节点表示一个城市，编号从 0 到 n - 1 ，且恰好有 n - 1 条路
// 0 是首都。给你一个二维整数数组 roads
// 其中 roads[i] = [ai, bi] ，表示城市 ai 和 bi 之间有一条 双向路
// 每个城市里有一个代表，他们都要去首都参加一个会议
// 每座城市里有一辆车。给你一个整数 seats 表示每辆车里面座位的数目
// 城市里的代表可以选择乘坐所在城市的车，或者乘坐其他城市的车
// 相邻城市之间一辆车的油耗是一升汽油
// 请你返回到达首都最少需要多少升汽油
// 测试链接 : https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/

#include <vector>
using namespace std;

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> graph(n);
        for(auto& r : roads){
            graph[r[0]].push_back(r[1]);
            graph[r[1]].push_back(r[0]);
        }
        vector<int> size(n);
        vector<long long> cost(n);
        f(graph, seats, 0, -1, size, cost);
		return cost[0];
    }

    void f(vector<vector<int>>& graph, int seats, int u, int p, vector<int>& size, vector<long long>& cost){
        size[u] = 1;
        for(int v : graph[u]){
            if(v != p){
                f(graph, seats, v, u, size, cost);
                size[u] += size[v];
                cost[u] += cost[v];
                // a/b向上取整，可以写成(a+b-1)/b
                cost[u] += (size[v] + seats - 1) / seats;
            }
        }
    }
};