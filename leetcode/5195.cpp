#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <cstring>
// #include <cstdlib>

using namespace std;

// accept
// 4ms, beats 100.00%
// 6.5MB, beats 100.00%
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> v;
        v.push_back({a, 'a'});
        v.push_back({b, 'b'});
        v.push_back({c, 'c'});

        string res;
        while (true) {
            sort(v.rbegin(), v.rend());
            int prelen = res.length();
            for (auto& [cnt, ch] : v) {
                if(cnt == 0 ||
                   (res.length() >= 2 &&
                    res[res.length() - 1] == ch &&
                    res[res.length() - 2] == ch)) {
                    continue;
                }
                res += ch;
                cnt--;
                break;
            }

            if(prelen == res.length()) break;
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.longestDiverseString(1, 1, 7) << endl;
    return 0;
}
