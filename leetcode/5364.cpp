#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        for (int i = 0; i < index.size(); ++i) {
            if(index[i] < res.size()) {
                res.insert(res.begin() + index[i], nums[i]);
            } else {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{

    Solution s;
    vector<int> nums = {1};
    vector<int> index = {0};
    vector<int> res = s.createTargetArray(nums, index);
    for(auto& e : res) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
