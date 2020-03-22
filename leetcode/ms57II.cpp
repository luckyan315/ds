#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// accept
// 4ms, 85.19%
// 9.2MB, 100.00%
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int l = 1;
        int r = 2;
        int half = target/2;
        while (l < r && l <= half) {
            int sum = (l + r) * (r - l + 1) / 2;
            if(sum == target) {
                vector<int> v;
                for (int i = l; i <= r; ++i) {
                    v.push_back(i);
                }
                res.push_back(v);
                l++;
            } else if (sum < target) r++;
            else l++;
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<int>> res = s.findContinuousSequence(9);
    for(auto& l : res){
        for(auto& e : l){
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}
