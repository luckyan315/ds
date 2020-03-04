#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// accept
// 12ms, beats 37.00%
// 15.9MB, beats 5.40%
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return -1;

        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        queue<vector<int>> que;
        int nrow = grid.size();
        int ncol = grid[0].size();
        int nfresh = 0;
        for (int i = 0; i < nrow; ++i) {
            for (int j = 0; j < ncol; ++j) {
                if(grid[i][j] == 2) que.push({i,j});
                if(grid[i][j] == 1) nfresh++;
            }
        }

        int cnt = 0;

        while (!que.empty()) {
            int size = que.size();
            bool isRotate = false;

            for (int i = 0; i < size; ++i) {
                auto node = que.front();
                int x = node[0];
                int y = node[1];
                que.pop();

                if(grid[x][y] == 0) continue;

                for (int d = 0; d < 4; d++) {
                    int nx = x + direction[d][0];
                    int ny = y + direction[d][1];

                    if (nx >= 0 && nx < nrow &&
                        ny >= 0 && ny < ncol &&
                        grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        que.push({nx, ny});
                        isRotate = true;
                        nfresh--;
                    }
                }
            }

            if(isRotate) cnt++;
        }

        return nfresh ? -1 : cnt;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<int>> input = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

    // vector<vector<int>> input = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};

    // vector<vector<int>> input = {{0, 2}};

    // vector<vector<int>> input = {{1, 2}};

    cout << s.orangesRotting(input) << endl;
    return 0;
}
