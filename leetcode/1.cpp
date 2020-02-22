#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// accept
// 16ms, beats 64.76%
// 10.3MB , 13.56%
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            int left = target - nums[i];
            auto it = umap.find(left);
            if (it != umap.end()) {
                return {i, it->second};
            }

            umap.insert({{nums[i], i}});
        }
        return vector<int>();
    }
};

// Runtime: 116 ms, faster than 38.45% of C++ online submissions for Two Sum.
// Memory Usage: 9.2 MB, less than 98.37% of C++ online submissions for Two Sum.

typedef std::unordered_map<int , int> intmap;

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        intmap m;
        for (int i = 0; i < nums.size(); i++) {
            auto t = m.find(target - nums[i]);
            if (t != m.end()){
                vector<int> vec(2);
                vec[0] = t->second;
                vec[1] = i;
                return vec;
            }
            m[nums[i]] = i;
        }

        return vector<int>(0, 0);
    }
};

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int left = target - nums[i];
            int j = nums.size() - 1;
            while (j >i) {
                if (left == nums[j]) {
                    vector<int> ret(2);
                    ret[0] = i;
                    ret[1] = j;
                    return ret;
                }
                j--;
            }
        }

        return vector<int>(0, 0);
    }
};

int main(int argc, char *argv[])
{
    Solution *pSln = new Solution();

    int arr[4] = {2,7,11,15};
    vector<int> nums(arr, arr + 4);
    int target = 9;

    const vector<int>& vec = pSln->twoSum(nums, target);
    if (vec.empty()) {
        delete pSln;
        return 1;
    }
    if (vec.size() >= 2) {
        cout<<vec[0] << vec[1] << endl;
    }

    delete pSln;
    return 0;
}
