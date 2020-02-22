#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 解题思路
// s[i] == s[j] 时候 dp[i][j] = dp[i + 1][j - 1] + 2
// s[i] != s[j] 时候 dp[i][j] = max(dp[i+1][j], [i][j - 1]))

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        const int LEN = s.length();

        vector<vector<int>> dp(LEN, vector<int>(LEN,0));

        for (int i = s.length() - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < s.length(); ++j) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
                }

            }
        }

        return dp[0][s.length() - 1];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string str1 = "bbbab";
    string str2 = "cbbd";
    cout << s.longestPalindromeSubseq(str2) << endl;
    return 0;
}
