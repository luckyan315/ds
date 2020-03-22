#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// accept
// 4ms, beats 84.92%
// 13MB, beats 5.20%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;

        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));

        for (int i = 0; i < prices.size(); ++i) {
            if(i == 0){
                dp[0][0] = 0;
                dp[0][1] = -prices[0];
                continue;
            }

            if(i == 1) {
                dp[1][0] = max(dp[0][1], dp[0][1] + prices[i]);
                dp[1][1] = max(dp[0][1], dp[0][0] - prices[i]);
                continue;
            }

            dp[i][0] = max(dp[i - 1][0], dp[i -1][1] + prices[i]);
            // 题目支持多次交易，所以计算 dp[i][1] 即 第i天持有股票最大收益
            // 时候有下面几种情况
            // 1. 前一天持有股票， 今天也继续持有, dp[i][1] = dp[i-1][1]
            // 2. 前2天没有持有股票, 今天买入股票
            // 前2天没有持有股票的时候有可能因为之前的买卖交易 已经产生了收益,
            // 这块收益因为有可能为负数， 比当从0收益前买入之后还要低，所以判断下
            // 之前收益率如果已经负数， 则前面所有交易放弃，改为从0开始交易当天股票
            dp[i][1] = max(dp[i - 1][1],
                           dp[i -2][0] < 0 ? -prices[i] : dp[i -2][0] - prices[i]);
        }

        return dp[prices.size() - 1][0] < 0 ? 0 : dp[prices.size() - 1][0];
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    vector<int> input = {1, 2, 3, 0, 2};
    // vector<int> input = {4, 2, 7, 1, 11};
    cout << s.maxProfit(input) << endl;
    return 0;
}
