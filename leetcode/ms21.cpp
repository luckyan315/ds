#include <iostream>
#include <vector>
#include <regex>

using namespace std;

// 44ms, beats 19.99%
// 19.7MB, beats 100.00%
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> arrOdd;
        vector<int> arrEven;

        for (auto& e : nums) {
            if(e % 2 == 1) {
                arrOdd.push_back(e);
            } else {
                arrEven.push_back(e);
            }
        }
        arrOdd.insert(arrOdd.end(), arrEven.begin(), arrEven.end());
        return arrOdd;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {1, 2, 3, 4, 5};
    vector<int> res = s.exchange(input);
    for (auto& e : res) {
        cout << e << " " << endl;
    }
    cout << endl;
    return 0;
}
