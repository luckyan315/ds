#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// accept
// 12ms, 31.72%
// 16.7MB, 5.02%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        for (int i = 0; i < prices.size(); ++i) {
            if(i == 0) {
                dp[0][0] = 0;
                dp[0][1] = -prices[0];
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[prices.size() - 1][0];
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    // vector<int> input = {7, 1, 5, 3, 6, 4};
    vector<int> input = {7, 6, 4, 3, 1};
    // vector<int> input = {7, 6, 4, 3, 1};
    // vector<int> input = {1, 2};
    cout << s.maxProfit(input) << endl;
    return 0;
}
