#include <iostream>
#include <string>

using namespace std;

// accept
// 12ms, beats 89.03%
class Solution1 {
public:
    int romanToInt(string s) {
        int ret = 0;
        bool isSpecial = false;

        for (int i = 0; i < s.length(); ++i) {
            switch(s[i]){
            case 'I':
                if (i + 1 < s.length() && (s[i+1] == 'V'|| s[i+1] == 'X')) {
                    isSpecial = true;
                } else {
                    ret += 1;
                }
                break;
            case 'V':
                if (isSpecial) {
                    ret += 4;
                    isSpecial = false;
                } else {
                    ret += 5;
                }
                break;
            case 'X':
                if (isSpecial) {
                    ret += 9;
                    isSpecial = false;
                } else {
                    if (i + 1 < s.length() && (s[i+1] == 'L' || s[i+1] == 'C')) {
                        isSpecial = true;
                    } else {
                        ret += 10;
                    }
                }
                break;
            case 'L':
                if (isSpecial) {
                    ret += 40;
                    isSpecial = false;
                } else {
                    ret += 50;
                }
                break;
            case 'C':
                if (isSpecial) {
                    ret += 90;
                    isSpecial = false;
                } else {
                    if (i + 1 < s.length() && (s[i+1] == 'D' || s[i+1] == 'M')) {
                        isSpecial = true;
                    } else {
                        ret += 100;
                    }
                }
                break;
            case 'D':
                if (isSpecial) {
                    ret += 400;
                    isSpecial = false;
                } else {
                    ret += 500;
                }
                break;
            case 'M':
                if (isSpecial) {
                    ret += 900;
                    isSpecial = false;
                } else {
                    ret += 1000;
                }
                break;
            }
        }
        return ret;
    }
};

class Solution {
public:
    int romanToInt(string s) {
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    if (argc < 2) {
        return 1;
    }
    cout << s.romanToInt(argv[1]) << endl;
    return 0;
}
