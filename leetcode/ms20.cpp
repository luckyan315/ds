#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if(s.length() == 0) return false;
        regex reg("^(\\s)*(\\+|-)?(([0-9]*\\.[0-9]*)|([0-9]+)(e(\\+|-)?[0-9]+)?(\\s)*$))");
        smatch sr;
        return regex_match(s, sr, reg);
    }
};

// accept
// class Solution {
//     public boolean isNumber(String s) {
//         return s.matches("^(\\s)*(\\+|-)?(([0-9]*\\.[0-9]+)|([0-9]+\\.[0-9]*)|[0-9]+)(e(\\+|-)?[0-9]+)?(\\s)*$");
//     }
// }

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.isNumber(argv[1]) << endl;
    return 0;
}
