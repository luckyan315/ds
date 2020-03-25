#include <iostream>
#include <string>

using namespace std;

// accept
// 560ms, beats 100%
// 15.9MB, beats 100.00%
class Solution {
public:
    string longestPrefix(string s) {
        for (int i = 1; i < s.length(); ++i) {
            if(0 == memcmp(s.c_str(), s.c_str() + i, s.length() - i)) {
                return s.substr(0, s.length() - i);
            }
        }
    }
};
