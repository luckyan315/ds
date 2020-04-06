#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <cstring>
// #include <cstdlib>

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        return cal(s);
    }


    int cal(string s) {
        if(s.length() == 1 && s[0] == '1') return 0;
        // cout << "cal: " << s << endl;
        string str;
        if(s[s.length() - 1] == '1') {
            str = addone(s);
        } else {
            str = rshift(s);
        }

        return 1 + cal(str);
    }

    string addone(string s) {
        int carry = 1;
        for (int i = s.length() - 1; i >= 0; --i) {
            int ch = s[i] - '0' + carry;
            if(ch == 2) {
                s[i] = '0';
                carry = 1;
            } else {
                s[i] = '1';
                carry = 0;
                break;
            }
        }
        if(carry == 1) {
            return "1" + s;
        }
        return s;
    }

    string rshift(string s) {
        if(s.length() <= 1) return "0";

        return s.substr(0, s.length() - 1);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.cal("11001") << endl;
    return 0;
}
