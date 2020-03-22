#include <iostream>
#include <string>

using namespace std;

// accept
// 8ms, beats 62.28%
// 8.3MB, beats 100.00%
class Solution {
public:
    bool check(string& str, int len, string& mask, int lenMask) {
        if(len % lenMask == 0) {
            int k = len / lenMask;
            string res;
            for (int i = 0; i < k; ++i) {
                res += mask;
            }
            return res == str;
        }
        return false;
    }

    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();

        int i = std::min(len1, len2);
        for (; i > 0; i--) {
            if(len1 % i == 0 && len2 % i == 0) {
                string mask = str1.substr(0, i);
                if(check(str1, len1, mask, i) && check(str2, len2, mask, i)) {
                    return mask;
                }
            }
        }
        return "";
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.gcdOfStrings("LEET", "CODE") << endl;
    return 0;
}
