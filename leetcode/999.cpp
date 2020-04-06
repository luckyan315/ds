#include <iostream>
#include  <vector>

using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x = 0;
        int y = 0;
        int res = 0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if(board[i][j] == 'R') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            while (nx >= 0 && nx < 8 &&
                   ny >= 0 && ny < 8) {
                if(board[nx][ny] == '.') {
                    nx += dir[i][0];
                    ny += dir[i][1];
                    continue;
                } else {
                    if(board[nx][ny] == 'p') {
                        res++;
                    }
                    break;
                }


            }
        }
        return res;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<char>> input = {{'.','.','.','.','.','.','.','.'},
                                  {'.','.','.','p','.','.','.','.'},
                                  {'.','.','.','R','.','.','.','p'},
                                  {'.','.','.','.','.','.','.','.'},
                                  {'.','.','.','.','.','.','.','.'},
                                  {'.','.','.','p','.','.','.','.'},
                                  {'.','.','.','.','.','.','.','.'},
                                  {'.','.','.','.','.','.','.','.'}};

    cout << s.numRookCaptures(input) << endl;
    return 0;
}
