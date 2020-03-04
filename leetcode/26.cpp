#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto iter = nums.begin();
        int prev = *iter;
        while (iter != nums.end()) {
            if(++iter != nums.end()) {
                if(*iter == prev){
                    nums.erase(iter);
                } else {
                    prev = *iter;
                }
            }
        }

        return nums.size();
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << s.removeDuplicates(input) << endl;

    for(auto& e : input) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
