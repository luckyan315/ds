#include <iostream>
#include <vector>

using namespace std;

// 参考 下面链接
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/gu-piao-wen-ti-python3-c-by-z1m/
// leetcode 121是通过 二维dp , 这个题其实可以使用一维dp来解决
// dpn = max(dp[n-1], nums[n] - minprice);
// accept
// 12ms, beats beats 46.97%
// 13MB, beats 100.00%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int dp0 = 0;
        int dpn = 0;
        int minprice = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            dpn = max(dp0, prices[i] - minprice);
            minprice = min(prices[i], minprice);
            dp0 = dpn;
        }
        return dpn;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(input) << endl;
    return 0;
}
