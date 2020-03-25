#include <iostream>
#include <vector>

using namespace std;

// accept
// 0ms, 100.00%
// 9.3MB, 100.00%
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size() + 1, 0);
        // dp[i] i个预约请求内 最长按摩时间
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
    // vector<int> input = {1, 2, 3, 1};
    vector<int> input = {2, 7, 9, 3, 1};
    cout << s.massage(input) << endl;
    return 0;
}
