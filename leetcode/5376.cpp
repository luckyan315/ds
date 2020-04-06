#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

// accept
// 20ms, beats 100.00%
// 10.7MB, beats 100.00%
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        vector<int> res;
        int retsum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            retsum += nums[i];
            res.push_back(nums[i]);
            if(retsum > sum - retsum) {
                return res;
            }
        }
        return res;
    }
};
