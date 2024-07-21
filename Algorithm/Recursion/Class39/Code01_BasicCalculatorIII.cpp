// 含有嵌套的表达式求值
// 测试链接 : https://leetcode.cn/problems/basic-calculator-iii/
#include <bits/stdc++.h>
using namespace std;

int where = 0;

int calculate(string& s);
int f(string& s, int i);
void pushArr(vector<int>& nums, vector<char>& ops, int cur, char op);
int compute(vector<int>& nums, vector<char>& ops);

int main(){
    string s = "2+3*(9+1+(2+2*(1+8))/2";
    cout << calculate(s) << endl;
    return 0;
}

int calculate(string& s){
    where = 0;
    return f(s, 0);
}

int f(string& s, int i){
    int cur = 0;
    vector<int> nums;
    vector<char> ops;
    while(i < s.size() && s[i] != ')'){
        if(s[i] >= '0' && s[i] <= '9'){
            cur = cur * 10 + s[i++] - '0';
        }else if(s[i] == '('){
            cur = f(s, i + 1);
            i = where + 1;
        }else{
            pushArr(nums, ops, cur, s[i++]);
            cur = 0;
        }
    }
    pushArr(nums, ops, cur, '+');
    where = i;
    return compute(nums, ops);
}

void pushArr(vector<int>& nums, vector<char>& ops, int cur, char op){
    if(nums.size() == 0 || ops.back() == '+' || ops.back() == '-'){
        nums.push_back(cur);
        ops.push_back(op);
    }else{
        int topNum = nums.back();
        char topOp = ops.back();
        nums.pop_back();
        ops.pop_back();
        if(topOp == '*'){
            nums.push_back(topNum * cur);
        }else{
            nums.push_back(topNum / cur);
        }
        ops.push_back(op);
    }
}

int compute(vector<int>& nums, vector<char>& ops){
    int n = nums.size();
    int ans = nums[0];
	for(int i = 1; i < n; i++){
		ans += ops[i - 1] == '+' ? nums[i] : -nums[i];
	}
	return ans;
}
