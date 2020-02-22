#include <iostream>
#include <vector>

using namespace std;

// accept
// 4ms, 82.20%
// 8.8MB, 5.05%
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int i = 0;
        while (i < size) {
            if(nums[i] == val) {
                nums[i] = nums[size - 1];
                size--;
            } else {
                i++;
            }

        }

        return size;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v = {3,2,2,3};
    cout << s.removeElement(v, 3) << endl;
    return 0;
}
