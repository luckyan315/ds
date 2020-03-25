#include <iostream>
#include <vector>

using namespace std;


// accept
// 0ms, 100.00%
// 9.1MB, 5.01%
// 迭代dp, 空间复杂度 O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        int dp0 = nums[0];
        int dp1 = max(nums[0], nums[1]);
        int dpn = nums[0];
        for (int i = 2; i < nums.size(); i++) {
            dpn = max(dp1, dp0 + nums[i]);
            dp0 = dp1;
            dp1 = dpn;
        }

        return dpn;
    }
};


// accept
// 8ms, beats 11.18%
// 9.1MB, beats 5.01%
class Solution1 {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        vector<int> dp(nums.size(), 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {2, 7, 9, 3, 1};
    cout << s.rob(input) << endl;
    return 0;
}
