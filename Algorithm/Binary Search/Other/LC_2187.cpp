#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        auto check = [&](long long x) -> bool {
            long long sum = 0;
            for(int t : time){
                sum += x / t;
                if(sum >= totalTrips){
                    return true;
                }
            }
            return false;
        };

        long long l = 1, r = (long long)totalTrips * *max_element(time.begin(), time.end());
        while(l < r){
            long long mid = (l + r) / 2;
            if(check(mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        return l;
    }
};