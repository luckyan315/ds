#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
// #include <cstdlib>

using namespace std;

// accept
// 996ms, beats 100.00%
// 132.3MB, beats 100.00%
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size() + 3, 0);
        int n = stoneValue.size();
        int i = n - 1;

        int sum = 0;
        for(; i >= 0; i--) {
            sum += stoneValue[i];
            dp[i] = INT_MIN;
            for (int j = i + 1; j <= i + 3; ++j) {
                dp[i] = max(dp[i], sum - dp[j]);
            }
        }

        int alice = dp[0];
        int bob = sum - dp[0];
        // cout << "alice: " << alice << " bob: " << bob << endl;
        if(alice > bob) {
            return "Alice";
        } else if (alice == bob) {
            return "Tie";
        } else {
            return "Bob";
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {1, 2, 3, 6};
    cout << s.stoneGameIII(input) << endl;
    return 0;
}
