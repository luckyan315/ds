#include <iostream>
#include <vector>

using namespace std;

// accept
// 12ms, beats 48.40%
// 8.8MB, beats 100.00%
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int r = grid.size();
        int c = grid[0].size();
        int cnt = 0;
        int dupCnt = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cnt += grid[i][j];
                if(grid[i][j] >1) {
                    dupCnt += grid[i][j] - 1;
                }

                if(j + 1 < c) {
                    dupCnt += min(grid[i][j], grid[i][j + 1]);
                }
                if(i + 1 < r) {
                    dupCnt += min(grid[i][j], grid[i + 1][j]);
                }
            }
        }
        // cout << "cnt: " << cnt << " dupCnt: " << dupCnt << endl;
        return cnt * 6 - dupCnt * 2;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    // vector<vector<int>> input = {{1, 2}, {3, 4}};
    // vector<vector<int>> input = {{1, 0}, {0, 2}};
    // vector<vector<int>> input = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> input = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
    cout << s.surfaceArea(input) << endl;
    return 0;
}
