#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// accept
// 4ms, beats 80.26%
// 8.2MB, beats 38.61%
class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for (int i = 0; i < s.length(); i++) {
            int carry = s[i] - 'A' + 1;
            ret += carry * pow(26, s.length() - i - 1);
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.titleToNumber(argv[1]) << endl;
    return 0;
}
