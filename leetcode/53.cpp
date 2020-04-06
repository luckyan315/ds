#include <iostream>
#include <vector>

using namespace std;

// accept
// 4ms, beats 97.81%
// 7MB, beats 100.00%
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp0 = nums[0];
        int res = dp0;
        int dpn = res;
        for(int i = 1; i < nums.size(); ++i){
            dpn = dp0 > 0 ? dp0 + nums[i] : nums[i];
            res = max(res, dpn);
            dp0 = dpn;
        }
        return res;
    }
};
