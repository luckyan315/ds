#include <iostream>
#include <vector>

using namespace std;

// accept
// 44ms, beats 20.46%
// 23.2MB, 100.00%
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        int dp0 = nums[0];
        int dp1 = dp0 > 0 ? dp0 + nums[1] : nums[1];
        if(nums.size() == 2) return max(dp0, dp1);

        // cout << dp0 << " " << dp1 << endl;

        int dpn = dp1;
        int res = max(dp0, dp1);
        for (int i = 2; i < nums.size(); ++i) {
            dpn = dp1 > 0 ? dp1 + nums[i] : nums[i];
            res = max(res, dpn);
            dp1 = dpn;
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {1, -1, -2};
    cout << s.maxSubArray(input) << endl;
    return 0;
}
