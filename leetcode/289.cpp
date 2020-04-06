#include <iostream>
#include <vector>

using namespace std;

// accept
// 0ms, beats 100.00%
// 7.1MB, beats 100.00%
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ori(board.begin(), board.end());
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                int cnt = nearby(i, j, ori);
                cout << "row: " << i << " col: " << j << " cnt: " << cnt << endl;
                if(board[i][j] == 1) {
                    if(cnt < 2) {
                        board[i][j] = 0;
                    } else if (cnt == 2 || cnt == 3) {
                        board[i][j] = 1;
                    } else if (cnt > 3) {
                        board[i][j] = 0;
                    }
                } else {
                    if(cnt == 3) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }

    int nearby(int r, int c, vector<vector<int>>& board) {
        int res = 0;
        for (int i = r - 1; i <= r + 1; ++i) {
            for (int j = c - 1; j <= c + 1; ++j) {
                if(i < 0 || i >= board.size() ||
                   j < 0 || j >= board[0].size() ||
                   (i == r && j == c)){
                    continue;
                }

                if(board[i][j] == 1) res++;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<int>> input = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    s.gameOfLife(input);

    for (auto& l : input) {
        for (auto& e: l) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}
