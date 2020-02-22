#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 4ms, 72.09%
// 8.1MB, 45.29%
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int  intMaxPowerOfTwo = (int) (log10(INT_MAX) / log10(2));
        int max_num = pow(2, intMaxPowerOfTwo);
        // cout << "int_max:" << INT_MAX << intMaxPowerOfThree << endl;
        return n > 0 && max_num % n == 0;
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    int n = argc == 2 ? atoi(argv[1]) : 27;
    cout << s.isPowerOfTwo(n) << endl;
    return 0;
}
