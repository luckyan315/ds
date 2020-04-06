#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution_fail {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        for (auto& e : deck) {
            mp[e]++;
        }

        if(deck.size() == 1) return false;

        int m = 0;
        for (auto& e : mp) {
            if(m == 0) {
                m = e.second;
                continue;
            }
            m = min(e.second, m);
            if(m == 1 && e.second > 1) return false;
            if(e.second % m != 0) return false;
        }

        return true;
    }
};

// accept
// 40ms, beats 7.47%
// 16.8MB, beats 5.71%
class Solution1 {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        for (auto& e : deck) {
            mp[e]++;
        }

        if(deck.size() == 1) return false;

        int g = 0;
        for (auto& e : mp) {
            if(g == 0) {
                g = e.second;
                continue;
            }

            g = gcd(g, e.second);
            if(g == 1) return false;
        }

        return true;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {0, 0, 0, 0, 0, 1, 1, 2, 3, 4};
    cout << s.hasGroupsSizeX(input) << endl;
    // cout << s.gcd(16, 12) << endl;
    return 0;
}
