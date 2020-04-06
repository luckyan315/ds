#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

// accept
// 152ms, beats 25.19%
// 16.4MB, beats 23.81%
class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int maxDistance(vector<vector<int>>& grid) {
        int ret = -1;
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> que;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1) {
                    que.push({i, j});
                }
            }
        }

        bool hasOcean = false;
        int fx = -1;
        int fy = -1;
        while (!que.empty()) {
            auto [x, y] = que.front();
            fx = x;
            fy = y;
            // cout << "visit: [" << fx << "," << fy << "] " << grid[fx][fy] << endl;
            que.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if(nx < 0 || nx >= row ||
                   ny < 0 || ny >= col ||
                   grid[nx][ny] != 0) {
                    continue;
                }
                hasOcean = true;
                // 标记陆地到到达该海洋的距离
                grid[nx][ny] = grid[x][y] + 1;
                que.push({nx, ny});
            }
        }

        if(fx == -1 || !hasOcean) return -1;

        return grid[fx][fy] - 1;
    }
};

class Solution_fail {
public:
    int m = INT_MAX;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int xbegin = 0;
    int ybegin = 0;

    int maxDistance(vector<vector<int>>& grid) {
        int ret = -1;
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j) {
                xbegin = i;
                ybegin = j;
                m = INT_MAX;
                vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), 0));
                if(!dfs(i, j, grid, vis)){
                    continue;
                }
                ret = max(ret, m);
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }

    bool dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        int row = grid.size();
        int col = grid[0].size();


        vis[x][y] = 1;

        if(grid[xbegin][ybegin] != grid[x][y]) {
            int curdist = abs(x - xbegin) + abs(y - ybegin);
            if(m != INT_MAX && m != curdist) {
                return false;
            }
            m = min(curdist, m);
            // cout << "enter: {" << xbegin << "," << ybegin << "}, exit: {" << x << "," << y << "}" <<
            //     " max dist: " << m << endl;
        }

        for (int i = 0; i < dir.size(); ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx >= 0 && nx < row &&
               ny >= 0 && ny < col &&
                vis[nx][ny] == 0) {
                if(!dfs(nx, ny, grid, vis)){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<int>> grid = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    cout << s.maxDistance(grid) << endl;
    return 0;
}
