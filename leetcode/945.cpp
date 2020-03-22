#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// accept
// 108ms, 30.34%
// 25.8MB, 20.83%
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());

        int m = 0;
        int res = 0;
        for (int i = 1; i < A.size(); ++i) {
            if(A[i] <= A[i - 1]) {
                res += (1 + A[i - 1] - A[i]);
                A[i] = A[i - 1] + 1;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {3, 2, 1, 2, 1, 7};
    // vector<int> input = {1, 2, 2};
    cout << s.minIncrementForUnique(input) << endl;
    return 0;
}
