#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// accept
// 12ms, 58.59%
// 11.5MB, 5.03%
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); ++j){
                if(j == 0 && i == 0) continue;

                if(i == 0 && j != 0) grid[i][j] += grid[i][j - 1];
                if(i != 0 && j == 0) grid[i][j] += grid[i - 1][j];
                if(i != 0 && j != 0) grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};

// 超出时间限制
class Solutionxx {
public:
    int minsum = INT_MAX;

    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;

        return grid[0][0] + std::min(dfs(1, 0, grid), dfs(0, 1, grid));
    }

    int dfs(int x, int y, vector<vector<int>>& grid) {
        if(x == grid.size() ||
           y == grid[0].size()) return INT_MAX;
        if(x == grid.size() - 1 && y == grid[0].size() - 1) return grid[x][y];
        return grid[x][y] + std::min(dfs(x + 1, y, grid), dfs(x, y + 1, grid));
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<int>> input = {{1, 2, 5},
                                 {3, 2, 1}};

    cout << s.minPathSum(input) << endl;
    return 0;
}
