#include <iostream>
#include <vector>

using namespace std;

// accept
// 0ms, beats 100.00%
// 8MB, beats 100.00%
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> mp(60, 0);

        for(auto& ch : s) {
            mp[ch - 'A']++;
        }

        int res = 0;
        int odd = 0;
        for(int i = 0; i < mp.size(); ++i){
            res += mp[i];
            if(mp[i] % 2 == 1) {
                odd++;
            }
        }

        return odd == 0 ? res : res - odd + 1;
    }
};
