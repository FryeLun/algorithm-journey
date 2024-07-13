// 航班预订统计
// 这里有 n 个航班，它们分别从 1 到 n 进行编号。
// 有一份航班预订表 bookings ，
// 表中第 i 条预订记录 bookings[i] = [firsti, lasti, seatsi]
// 意味着在从 firsti 到 lasti 
//（包含 firsti 和 lasti ）的 每个航班 上预订了 seatsi 个座位。
// 请你返回一个长度为 n 的数组 answer，里面的元素是每个航班预定的座位总数。
// 测试链接 : https://leetcode.cn/problems/corporate-flight-bookings/

/*
void Add(int c, int l, int r) {
	b[l] += c;
	b[r + 1] -= c;
}
void build(int n){
    for (int i = 1; i <= n; i++) {
		b[i] += b[i - 1];
	}
}
*/

#include<vector>
using namespace std;

class Solution {
public:
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
		vector<int> cnt(n + 2, 0);
		for (auto& book : bookings) {
			cnt[book[0]] += book[2];
			cnt[book[1] + 1] -= book[2];
		}
		for (int i = 1; i < cnt.size(); i++) {
			cnt[i] += cnt[i - 1];
		}
		vector<int> ans(n, 0);
		for (int i = 0; i < n; i++) {
			ans[i] = cnt[i + 1];
		}
		return ans;
	}
};