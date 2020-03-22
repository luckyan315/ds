#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// accept
// dp
// 12ms, 47.51%
// 16.6MB, 5.11%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;

        // dp[i][j]:
        // i = 0, 代表第一天
        // j = 0, 代表没有股票, j = 1, 代表持有股票
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));

        int i = 0;
        for (; i < prices.size(); ++i) {
            if(i == 0) {
                dp[0][0] = 0;
                dp[0][1] = -prices[0];
                continue;
            }
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = std::max(dp[i - 1][1],  - prices[i]);
        }

        return dp[i - 1][0];
    }
};

// 12ms, 42.39%
// 15.1MB, 5.05%
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int _max = 0;
        int minprice = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            _max = std::max(_max, prices[i] - minprice);
            minprice = std::min(minprice, prices[i]);
        }

        return _max;
    }
};

// 2572ms, 5.02%
// 15.3MB, 5.05%
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int _max = INT_MIN;
        for (int i = 0; i < prices.size() - 1; ++i) {

            for (int j = i + 1; j < prices.size(); ++j) {
                if(prices[j] < prices[i]) continue;

                int profit = prices[j] - prices[i];
                _max = std::max(_max, profit);
            }
        }

        return _max == INT_MIN ? 0 : _max;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {7, 1, 5, 3, 6, 4};
    // vector<int> input = {7, 6, 4, 3, 1};
    // vector<int> input = {1, 2};
    cout << s.maxProfit(input) << endl;
    return 0;
}
