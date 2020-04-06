#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {

        unsigned long long cnt = 0;



        return cnt % 1000000007;
    }
};

class Solution_timeout {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {

        unsigned long long cnt = 0;
        if(s1.find(evil) == string::npos) cnt++;
        string s = next(s1);
        while (s <= s2) {
            if(s.find(evil) == string::npos) {
                cout << "find: " << s << endl;
                cnt++;
            }
            s = next(s);
        }
        return cnt % 1000000007;
    }
    string next(string& str) {
        string res;
        int carry = 1;
        for (int i = str.length() - 1; i >= 0; i--) {
            int cur = str[i] - 'a' + carry;
            if(cur == 26) {
                carry = 1;
                cur = 0;
            } else {
                carry = 0;
            }

            res += (char)('a' + cur);
        }
        // cout << "next.res: " << res << endl;
        return string(res.rbegin(), res.rend());
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.findGoodStrings(8, "pzdanyao", "wgpmtywi", "sdka") << endl;
    return 0;
}
