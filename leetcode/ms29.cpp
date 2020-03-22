#include <iostream>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

// accept
// 8ms, beats 94.71%
// 14.7MB, beats 100.00%
class Solution {
public:
    enum Dir{RIGHT, DOWN, LEFT, UP};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return vector<int>();
        vector<vector<int>> vis(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<int> res;
        Dir dir = Dir::RIGHT;
        visit(0, 0, matrix, vis, res, dir);
        return res;
    }

    void visit(int x, int y, vector<vector<int>>& matrix,
             vector<vector<int>>& vis,
               vector<int>& res, Dir& dir) {
        if(x < 0 || x >= matrix.size() ||
           y < 0 || y >= matrix[0].size() ||
           vis[x][y] == 1) {
            dir = Dir((dir + 1) % 4);
            return;
        }

        vis[x][y] = 1;
        res.push_back(matrix[x][y]);

        switch(dir) {
        case Dir::RIGHT:
            if(y + 1 < matrix[0].size() && vis[x][y + 1] == 0) visit(x, y + 1, matrix, vis, res, dir);
            else dir = Dir::DOWN;
        case Dir::DOWN:
            if(x + 1 < matrix.size() && vis[x + 1][y] == 0) visit(x + 1, y, matrix, vis, res, dir);
            else dir = Dir::LEFT;
        case Dir::LEFT:
            if(y - 1 >= 0 && vis[x][y - 1] == 0) visit(x, y - 1, matrix, vis, res, dir);
            else dir = Dir::UP;
        case Dir::UP:
            if(x - 1 >= 0 && vis[x - 1][y] == 0) visit(x - 1, y, matrix, vis, res, dir);
            else {
                dir = Dir::RIGHT;
                if(y + 1 < matrix[0].size()) visit(x, y + 1, matrix, vis, res, dir);
            }
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    // vector<vector<int>> input = {{1, 2, 3},
    //                              {4, 5, 6},
    //                              {7, 8, 9}};

    // vector<vector<int>> input = {{1, 2, 3, 4},
    //                              {5, 6, 7, 8},
    //                              {9, 10, 11, 12}};

    vector<vector<int>> input = {{1, 2, 3, 4},
                                 {5, 6, 7, 8},
                                 {9, 10, 11, 12},
                                 {13,  14, 15, 16}};


    vector<int> res = s.spiralOrder(input);
    for(auto& e : res) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
