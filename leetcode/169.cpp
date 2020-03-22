#include <iostream>
#include <vector>

using namespace std;

// accept
// 52ms, 5.45%
// 21.1MB, 5.28%
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int cnt = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i - 1]) cnt++;
            else cnt = 1;
            if(cnt > nums.size()/2) {
                return nums[i];
            }
        }
        return nums[0];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    // vector<int> input = {3, 2, 3};
    vector<int> input = {-1, 1, 1, 1, 2, 1};
    cout << s.majorityElement(input) << endl;
    return 0;
}
