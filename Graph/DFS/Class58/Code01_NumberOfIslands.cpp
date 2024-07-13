// 岛屿数量
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成
// 此外，你可以假设该网格的四条边均被水包围
// 测试链接 : https://leetcode.cn/problems/number-of-islands/

#include<vector>
using namespace std;

class Solution {
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<char>>& grid, int x, int y){
        if(x < 0 || x == grid.size() || y < 0 || y == grid[0].size() || grid[x][y] != '1'){
            return;
        }
        grid[x][y] = '0';
        for(int i = 0;i < 4;i++){
            dfs(grid, x + dx[i], y + dy[i]);
        }
    }
};