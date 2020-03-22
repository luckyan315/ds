#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int res = 0;
        for (int i = 0; i < s.length() - 1; ++i) {
            string pre = s.substr(0, i + 1);
            string sub = s.substr(s.length() - i - 1);

            hash<string> strhash;

            // cout << "pre: " << pre << " sub: " << sub << endl;
            // cout << "hash_pre: " << strhash(pre) << " hash_sub: " << strhash(sub) << endl;
            if(strhash(pre) != strhash(sub)) continue;

            res = max(res, i + 1);
        }
        // cout << res << endl;
        return s.substr(0, res);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.longestPrefix("a") << endl;
    return 0;
}
