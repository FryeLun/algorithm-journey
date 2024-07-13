// 二维接雨水
// 给你一个 m * n 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度
// 请计算图中形状最多能接多少体积的雨水。
// 测试链接 : https://leetcode.cn/problems/trapping-rain-water-ii/

#include <vector>
#include <queue>
using namespace std;

class Point {
public:
	int x;
	int y;
	int height;
	Point(int i, int j, int h) : x(i), y(j), height(h) {}
	bool operator <(const Point& a) const {
		return height > a.height;
	}
};

class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		int move[5] = { -1, 0, 1, 0, -1 };
		int n = heightMap.size();
		int m = heightMap[0].size();
		priority_queue<Point> heap;
		bool visited[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
					heap.push(Point(i, j, heightMap[i][j]));
					visited[i][j] = true;
				}
				else {
					visited[i][j] = false;
				}
			}
		}
		int ans = 0;
		while (!heap.empty()) {
			Point record = heap.top();
			heap.pop();
			int r = record.x;
			int c = record.y;
			int w = record.height;
			ans += w - heightMap[r][c];
			for (int i = 0, nr, nc; i < 4; i++) {
				nr = r + move[i];
				nc = c + move[i + 1];
				if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) {
					heap.push(Point(nr, nc, max(heightMap[nr][nc], w)));
					visited[nr][nc] = true;
				}
			}
		}
		return ans;
	}
};