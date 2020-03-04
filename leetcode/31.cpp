#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

// accept
// 4ms, 92.55%
// 14.5MB, 5.03%
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

// timeout
class Solution1 {
public:
    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        permute(res, nums, path);

        sort(res.begin(), res.end());

        res.erase(unique(res.begin(), res.end()), res.end());

        for (int i = 0; i < res.size(); ++i) {
            int j = 0;
            for(; j < res[0].size(); ++j) {
                if(res[i][j] != nums[j]) break;
            }

            if(j == res[0].size()) {
                if(i + 1 == res.size()) {
                    nums.assign(res[0].begin(), res[0].end());
                } else {
                    nums.assign(res[i + 1].begin(), res[i + 1].end());
                }
                return;
            }
        }
    }

    void permute(vector<vector<int>>& res, vector<int>& nums, vector<int>& path) {
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

            permute(res, subnums, path);
            path.pop_back();
        }
    }

};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> arr={1, 1, 5};
    s.nextPermutation(arr);

    for (auto &e : arr) {
        cout<<e;
    }
    cout<<"\n";


    return 0;
}
