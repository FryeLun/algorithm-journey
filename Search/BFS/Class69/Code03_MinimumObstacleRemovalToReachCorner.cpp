// 到达角落需要移除障碍物的最小数目
// 给你一个下标从 0 开始的二维整数数组 grid ，数组大小为 m x n
// 每个单元格都是两个值之一：
// 0 表示一个 空 单元格，
// 1 表示一个可以移除的 障碍物
// 你可以向上、下、左、右移动，从一个空单元格移动到另一个空单元格。
// 现在你需要从左上角 (0, 0) 移动到右下角 (m - 1, n - 1) 
// 返回需要移除的障碍物的最小数目
// 测试链接 : https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/

#include <vector>
#include <cstring>
#include <deque>
using namespace std;

class Solution {
public:
   int minimumObstacles(vector<vector<int>>& grid) {
       int move[5] = { -1, 0, 1, 0, -1 };
       int m = grid.size();
       int n = grid[0].size();
       int distance[m][n];
       memset(distance, 0x3f, sizeof(distance));
       deque<pair<int, int>> q;
       q.push_front({ 0, 0 });
       distance[0][0] = 0;
       while (!q.empty()) {
           auto record = q.front();
           q.pop_front();
           int x = record.first;
           int y = record.second;
           if (x == m - 1 && y == n - 1) {
               return distance[x][y];
           }
           for (int i = 0; i < 4; i++) {
               int nx = x + move[i], ny = y + move[i + 1];
               if (nx >= 0 && nx < m && ny >= 0 && ny < n && distance[x][y] + grid[nx][ny] < distance[nx][ny]) {
                   distance[nx][ny] = distance[x][y] + grid[nx][ny];
                   if (grid[nx][ny] == 0) {
                       q.push_front({ nx, ny });
                   }
                   else {
                       q.push_back({ nx, ny });
                   }
               }
           }
       }
       return -1;
   }
};