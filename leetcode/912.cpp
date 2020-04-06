#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        return bubleSort(nums);
    }

    vector<int> bubleSort_timeout(vector<int>& nums) {

    }

    vector<int> bubleSort_timeout(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if(nums[j] < nums[i]) {
                    nums[j] ^= nums[i];
                    nums[i] ^= nums[j];
                    nums[j] ^= nums[i];
                }
            }
        }
        return nums;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {5, 2, 3, 1};
    vector<int> res = s.sortArray(input);
    for (auto& e : res) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
