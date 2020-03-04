#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;


// accept
// 320ms, beats 8.49%
// 48.1MB, beats 5.03%

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        permuteNext(res, nums, path);

        sort(res.begin(), res.end());

        res.erase(unique(res.begin(), res.end()), res.end());

        return res;
    }

    void permuteNext(vector<vector<int>>& res, vector<int>& nums, vector<int>& path) {
        if(nums.size() == 0) return;

        if(nums.size() == 1) {
            path.push_back(nums[0]);
            res.push_back(path);
            path.pop_back();
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            path.push_back(nums[i]);
            vector<int> subnums(nums);
            // vector<int> subpath(path);
            subnums.erase(subnums.begin() + i);

            permuteNext(res, subnums, path);
            path.pop_back();
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> arr={1,1,2};
    vector<vector<int>> ret;
    ret = s.permuteUnique(arr);

    for (auto &v : ret) {
        for (auto &e : v) {
            cout<<e;
        }
        cout<<"\n";
    }

    return 0;
}
