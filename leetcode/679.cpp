#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;

                for (int k = 0; k < nums.size(); ++k) {
                    if (k == i || k == j) continue;

                    if (solve(nums[i], nums[j], '+')) return true;
                }
            }
        }

        return false;
    }

    bool solve(int a, int b, char op){

    }

};

int main(int argc, char *argv[])
{
    Solution s;

    std::vector<int> nums = {4,1,8,7};

    s.judgePoint24(nums);
    return 0;
}
