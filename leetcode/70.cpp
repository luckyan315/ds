#include <iostream>

using namespace std;

// accept
// 0ms, 100.00%
// 5.9MB, 100.00%
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;

        int dp1 = 1;
        int dp2 = 2;
        int dpn = dp1;
        for (int i = 3; i <= n; ++i) {
            dpn = dp1 + dp2;
            dp1 = dp2;
            dp2 = dpn;
        }
        return dpn;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
