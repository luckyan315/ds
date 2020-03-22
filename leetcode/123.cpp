#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// accept
// 24ms, beats 26.23%
// 21MB, beats 5.16%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(2, 0)));
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = 1; j >= 0; --j) {
                if(i == 0) {
                    dp[0][j][0] = 0;
                    dp[0][j][1] = -prices[0];
                    continue;
                }
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                if(j == 0) {
                    dp[i][j][1] = max(dp[i - 1][j][1],  - prices[i]);
                } else {
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                }

            }
        }
        return dp[prices.size() - 1][1][0];
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    // vector<int> input = {7, 1, 5, 3, 6, 4};
    // vector<int> input = {3, 3, 5,0, 0, 3, 1, 4};
    vector<int> input = {7, 6, 4, 3, 1};
    // vector<int> input = {7, 6, 4, 3, 1};
    // vector<int> input = {1, 2};
    cout << s.maxProfit(input) << endl;
    return 0;
}
