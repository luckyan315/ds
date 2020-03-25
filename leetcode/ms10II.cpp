#include <iostream>
#include <vector>

using namespace std;

// 0ms, 100.00%
// 5.7MB, 100.00%
class Solution {
public:
    int numWays(int n) {
        if(n == 2) return 2;
        if(n == 1) return 1;

        long long dp1 = 1;
        long long dp2 = 2;
        long long dpn = dp1;
        for (int i = 3; i <= n; ++i) {
            dpn = (dp1 + dp2) % 1000000007;

            dp1 = dp2;
            dp2 = dpn;
        }
        return dpn;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.numWays(95) << endl;
    return 0;
}
