#include <iostream>
#include <vector>

using namespace std;

// accept
// 20ms, beats 58.82%
// 24.9MB, 5.55%
class Solution {
public:
    int maxArea = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1) {
                    int cnt = 0;
                    bfs(i, j, grid, cnt);
                }
            }
        }

        return maxArea;
    }

    void bfs(int x, int y, vector<vector<int>>& grid, int& count) {
        if(x < 0 || x >= grid.size() ||
           y < 0 || y >= grid[0].size() ||
            grid[x][y] == 0) {
            return;
        }

        grid[x][y] = 0;
        count++;
        maxArea = max(maxArea, count);

        if(y + 1 < grid[0].size()) bfs(x, y + 1, grid, count);
        if(y - 1 >= 0) bfs(x, y - 1, grid, count);
        if(x + 1 < grid.size()) bfs(x + 1, y, grid, count);
        if(x - 1 >= 0) bfs(x - 1, y, grid, count);
    }
};

// accept
// 1404ms, 5.44%
// 486.6MB, 5.18%
class Solution1 {
public:
    int maxArea = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1) {
                    int cnt = 0;
                    vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
                    bfs(i, j, grid, vis, cnt);
                }
            }
        }

        return maxArea;
    }

    void bfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis, int& count) {
        if(x < 0 || x >= grid.size() ||
           y < 0 || y >= grid[0].size() ||
            vis[x][y] == 1) {
            return;
        }
        if(grid[x][y] == 0) return;

        vis[x][y] = 1;
        count++;
        maxArea = max(maxArea, count);

        bfs(x, y + 1, grid, vis, count);
        bfs(x, y - 1, grid, vis, count);
        bfs(x + 1, y, grid, vis, count);
        bfs(x - 1, y, grid, vis, count);
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> input = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                 {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                 {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                 {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                 {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                 {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                 {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    Solution s;
    cout << s.maxAreaOfIsland(input) << endl;
    return 0;
}
