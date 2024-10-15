#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        long long h = round(hour * 100);
        if(h <= (n - 1) * 100){
            return -1;
        }
        int l = 0, r = 1e7;
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if(check(mid, dist, h)){
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }

    bool check(int v, vector<int>& dist, long long h){
        long long t = 0;
        for(int i = 0; i < dist.size() - 1; i++){
            t += (dist[i] - 1) / v + 1;
        }
        return (t * v + dist.back()) * 100 <= h * v;
    }
};