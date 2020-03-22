#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// accept
// 8ms, beats 99.25%
// 12.2MB, beats 89.38%
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0 || amount == 0) return 0;
        sort(coins.begin(), coins.end(), greater<int>());
        int res = INT_MAX;

        dfs(0, coins, amount, 0, res);

        return res == INT_MAX ? -1 : res;
    }

    void dfs(int idx, vector<int>& coins, int amount, int coinCnt, int& res) {
        if(idx >= coins.size()) return;

        for (int c = amount / coins[idx]; c >= 0; c--) {
            int left = amount - c * coins[idx];
            int cnt = coinCnt + c;
            if(left == 0) {
                res = std::min(cnt, res);
                break;
            }
            if(cnt + 1 >= res) break;

            dfs(idx + 1, coins, left, cnt, res);
        }
    }
};

// 作者：biubiu-52
// 链接：https://leetcode-cn.com/problems/coin-change/solution/tan-xin-dfs-by-biubiu-52/
// 0ms, 100.00%
// 12.2MB, 88.73%
class Solution_copy_from_leetcode {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX;
        coinChange(coins, amount, 0, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }
    void coinChange(vector<int>& coins, int amount, int c_index, int count, int& ans)
        {
            if (amount == 0)
            {
                ans = min(ans, count);
                return;
            }
            if (c_index == coins.size()) return;

            for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)
            {
                coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
            }
        }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {186, 419, 83, 408};

    cout << s.coinChange(input, 6249) << endl;
    return 0;
}
