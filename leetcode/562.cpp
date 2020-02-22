#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// accept
// time: 48ms, 95.45%
// memory: 15.3MB, 100.00%
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        const int LEN = M.size();
        if (LEN == 0) {
            return 0;
        }
        int dp[LEN][M[0].size()][4];
        memset(dp, 0, sizeof(dp));
        int ans = 0;

        for (int i = 0; i < LEN; ++i) {
            for (int j = 0; j < M[0].size(); ++j) {
                if (M[i][j] == 1) {
                    // horizontal
                    dp[i][j][0] = j > 0 ? dp[i][j - 1][0] + 1 : 1;
                    // vertical
                    dp[i][j][1] = i > 0 ? dp[i - 1][j][1] + 1 : 1;
                    // diagonal
                    dp[i][j][2] = (i > 0 && j > 0) ? dp[i - 1][j - 1][2] + 1 : 1;
                    // back-diagonal
                    dp[i][j][3] = (i > 0 && j < (M[0].size() - 1)) ? dp[i - 1][j + 1][3] + 1 : 1;
                    for (auto& e : dp[i][j]) {
                        if (ans < e) ans = e;
                    }
                }


            }
        }

        return ans;
    }
};


// accept
// time costs 84ms/50.00%, memory costs: 33.9MB/100.00%
// dp[i][j][0]: 经过此坐标(i,j)的horizontal（横向） 最长连续1
// dp[i][j][1]: 经过此坐标(i,j)的vertical（竖向） 最长连续1
// dp[i][j][2]: 经过此坐标(i,j)的diagnal（对角线） 最长连续1
// dp[i][j][3]: 经过此坐标(i,j)的back-diagnal（反对角线） 最长连续1

class Solution2 {
public:
    typedef std::vector<int>  IntVector;
    typedef std::vector<IntVector>    IntVector2D;
    typedef std::vector<IntVector2D>    IntVector3D;


    int longestLine(vector<vector<int>>& M) {
        const int LEN = M.size();
        if (LEN == 0) {
            return 0;
        }
        IntVector3D dp(LEN, IntVector2D(M[0].size(), IntVector(4, 0)));
        int ans = 0;

        for (int i = 0; i < LEN; ++i) {
            for (int j = 0; j < M[0].size(); ++j) {
                if (M[i][j] == 1) {
                    // horizontal
                    dp[i][j][0] = j > 0 ? dp[i][j - 1][0] + 1 : 1;
                    // vertical
                    dp[i][j][1] = i > 0 ? dp[i - 1][j][1] + 1 : 1;
                    // diagonal
                    dp[i][j][2] = (i > 0 && j > 0) ? dp[i - 1][j - 1][2] + 1 : 1;
                    // back-diagonal
                    dp[i][j][3] = (i > 0 && j < (M[0].size() - 1)) ? dp[i - 1][j + 1][3] + 1 : 1;
                    for (auto& e : dp[i][j]) {
                        if (ans < e) ans = e;
                    }
                }


            }
        }

        return ans;
    }
};


int main(int argc, char *argv[])
{
    Solution s;

    vector<vector<int>> input =
        {{0,1,1,0,1},
         {0,1,1,0,1},
         {0,0,0,1,1},
         {0,1,1,0,1},
         {0,1,0,0,1}};

    cout << s.longestLine(input) << endl;
    return 0;
}
