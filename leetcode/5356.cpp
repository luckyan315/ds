#include <iostream>
#include <vector>

using namespace std;

// accept
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return vector<int>();
        vector<int> maxRow(matrix.size(), INT_MAX);
        vector<int> maxCol(matrix[0].size(), INT_MIN);

        for (int r = 0; r < maxRow.size(); ++r) {
            for (int c = 0; c < maxCol.size(); ++c) {
                if(matrix[r][c] < maxRow[r]) maxRow[r] = matrix[r][c];
                if(matrix[r][c] > maxCol[c]) maxCol[c] = matrix[r][c];
            }
        }

        vector<int> res;
        for (int i = 0; i < maxRow.size(); ++i) {
            for (int j = 0; j < maxCol.size(); ++j) {
                if(matrix[i][j] == maxRow[i] &&
                   matrix[i][j] == maxCol[j]) {
                    res.push_back(matrix[i][j]);
                }
            }
        }
        return res;
    }
};
