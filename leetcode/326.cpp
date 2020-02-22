#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 28ms, 44.29%
// 8.1MB, 41.92%
class Solution {
public:
    bool isPowerOfThree(int n) {
        int  intMaxPowerOfThree = (int) (log10(INT_MAX) / log10(3));
        int max_num = pow(3, intMaxPowerOfThree);
        // cout << "int_max:" << INT_MAX << intMaxPowerOfThree << endl;
        return n > 0 && max_num % n == 0;
    }
};

// accept
// 36ms, 17.27%
// 8MB, 68.20%
class Solution1 {
public:
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

int main(int argc, char *argv[])
{
    for (int i = 0; i <= 19; ++i) {
        cout << pow(3, i) << ",";
    }
    Solution s;
    int n = argc == 2 ? atoi(argv[1]) : 27;
    cout << s.isPowerOfThree(n) << endl;
    return 0;
}
