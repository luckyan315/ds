#include <iostream>
#include <cmath>

using namespace std;

// accept
// 8ms, 25.58%
// 8MB, 59.55%
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 1) return false;
        while(num % 4 == 0){
            num /= 4;
        }
        return num == 1;
    }
};

class Solutionxx {
public:
    bool isPowerOfFour(int num) {
        int powoffour = (int) log10(INT_MAX) / log10(4);
        int maxnum = pow(4, powoffour);
        cout << "maxnum:" << maxnum << " powoffour:" << powoffour << " num: " << num << endl;
        return num == 1 || num == 4 || (num > 0 && maxnum % num == 0);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int n = argc == 2 ? atoi(argv[1]) : 5;
    cout << s.isPowerOfFour(n) << endl;
    return 0;
}
