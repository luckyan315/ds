#include <iostream>
#include <string>
#include <vector>

using namespace std;

// accept
// 32ms , beats 71.36%
// 11.7MB, beats 48.98%

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> marked(board.size(), vector<bool>(board[0].size(), false));
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                // cout << "iterate: row: " << row << " col: " << col << endl;
                if (bfs(board, row, col, word, 0, marked)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool bfs (vector<vector<char>>& board, int row, int col, string& word, int index, vector<vector<bool>>& marked) {
        // cout << "visit row: " << row << " col: " << col
        //      << " board[row][col]:" << board[row][col]
        //      << " word index: " << index << endl;

        if (row >= board.size() || col >= board[0].size() || row < 0 || col < 0 || index >= word.length() || word[index] != board[row][col] || marked[row][col]) {
            return false;
        }

        if (index == word.length() - 1) {
            return true;
        }

        marked[row][col] = true;

        if (bfs(board, row, col + 1, word, index + 1, marked)) {
            return true;
        }

        if(bfs(board, row + 1, col, word, index + 1, marked)){
            return true;
        }

        if (bfs(board, row, col - 1, word, index + 1, marked)) {
            return true;
        }

        if (bfs(board, row - 1, col, word, index + 1, marked)) {
            return true;
        }

        marked[row][col] = false;

        return false;
    }
};


// accept
// 24ms, beats 88.57%
// 10.1MB, beats 77.75%
class Solution1 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                // cout << "iterate: row: " << row << " col: " << col << endl;
                // vector<vector<bool>> marked(board.size(), vector<bool>(board[0].size(), false));
                if (bfs(board, row, col, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool bfs (vector<vector<char>>& board, int row, int col, string& word, int index) {
        // cout << "visit row: " << row << " col: " << col
        //      << " board[row][col]:" << board[row][col]
        //      << " word index: " << index << endl;
        if (row >= board.size() || col >= board[0].size() || row < 0 || col < 0 || index >= word.length() || board[row][col] != word[index]){
            return false;
        }

        if (index == word.length() - 1) {
            return true;
        }

        board[row][col] = '.';
        bool ret = bfs(board, row, col + 1, word, index + 1) ||
            bfs(board, row + 1, col, word, index + 1) ||
            bfs(board, row, col - 1, word, index + 1) ||
            bfs(board, row - 1, col, word, index + 1);
        board[row][col] = word[index]; // 进行回溯
        return ret;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};

    Solution s = Solution();
    string word("ABCCEE"); // true;
    // string word("ABCB"); // false;
    // string word("SEE"); // true

    if(s.exist(board, word)){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
