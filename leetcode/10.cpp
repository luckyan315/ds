#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// accept
// 24ms, beats 47.51%
// 8.7MB, beats 71.72%
class Solution2 {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }

    bool isMatch(const char* s, const char* p) {
        if (*p == 0) return *s == 0;

        bool isFirstMatch = *s && (*s == *p || *p == '.');
        if (*(p + 1) == '*') {
            return isMatch(s, p+2) || (isFirstMatch && isMatch(++s, p));
        } else {
            return isFirstMatch && isMatch(++s, ++p);
        }
    }
};


// accept
// 276ms, beats 22.95%
// 15.5MB, beats 8.55%
class Solution1 {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();

        bool isFirstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (p.length() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (isFirstMatch && isMatch(s.substr(1), p));
        } else {
            return isFirstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sln;
    if (argc <= 2) {
        return -1;
    }


    cout << "argv[1]: " << argv[1] << " artv[2]: " << argv[2] << endl;

    if (sln.isMatch(argv[1], argv[2])) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
