#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 动态规划解法
// accept
// 76ms, beats 14.84%
// 8.8MB, beats 8.49%
class Solution3 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int maxLen = 1;

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; j++) {
                // {3,5,6,2,5,4,19,5,6,7,12};
                int cur = nums[i] > nums[j] ? dp[j] + 1 : 1;
                dp[i] = max(dp[i], cur);
            }
            maxLen = maxLen < dp[i] ? dp[i] : maxLen;
        }
        return maxLen;
    }
};

// accept,
// 8ms, beats 81.26%
// 8.7MB, beats 26.21%
// 二分法
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            // binary search
            int low = 0, high = ret.size() - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[i] > ret[mid]) low = mid + 1;
                else if (nums[i] <= ret[mid]) high = mid - 1;
            }
            if (low == ret.size()) {
                ret.insert(ret.begin() + low, nums[i]);
            } else if (low < ret.size()) {
                ret[low] = nums[i];
            }

            // debug
            // cout << "i: " << i << endl;
            // for(auto& e : ret) cout << e << " ";
            // cout << endl;
        }

        return ret.size();
    }
};


class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> ret(nums.size(), 0);
        int len = 0;
        for (int e : nums) {
            // binary search
            int low = 0, high = len - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (e > ret[mid]) low = mid + 1;
                else if (e < ret[mid]) high = mid - 1;
                else {
                    low = mid;
                    break;
                }
            }

            if (low >= 0 && low < ret.size()) {
                ret[low] = e;
                // debug
                for (auto& em : ret) {
                    cout << em << " ";
                }
                cout << endl;
            }

            if (low == len) ++len;
        }

        return len;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    // vector<int> v = {10,9,2,5,3,7,101,18};
    // vector<int> v = {2,2};
    vector<int> v = {3,5,6,2,5,4,19,5,6,7,12};
    cout << s.lengthOfLIS(v) << endl;
    return 0;
}
