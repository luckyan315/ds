#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


// accept
// 20ms, beats 100%
// 12MB, beats 55.70%
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0];
        int right = matrix.back().back();
        while (left < right) {
            int mid = left + (right - left)/2;
            int cntLessMid = 0;
            for(int i = 0; i < matrix.size(); ++i) {
                cntLessMid += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }

            if (cntLessMid < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

// accept
// 44ms, beats 65.34%
// 13.5MB, 13.92%
class Solution2 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0) return 0;
        priority_queue<int> que;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                int e = matrix[i][j];
                if (que.size() < k) {
                    que.push(e);
                } else if (matrix[i][j] < que.top()) {
                    que.pop();
                    que.push(matrix[i][j]);
                }
            }
        }

        return que.top();
    }
};



// accept
// 48ms, beats 60.78%
// 14.5MB, beats 9.18%
class Solution1 {
public:
    struct cmp {
        bool operator () (pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
        }
    };

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0) return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                int e = matrix[i][j];
                if (que.size() < k) {
                    que.push({e, i * matrix[0].size() + j});
                } else if (matrix[i][j] < que.top().first) {
                    que.pop();
                    que.push({matrix[i][j], i * matrix[0].size() + j});
                }
            }
        }

        return que.top().first;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    // vector<vector<int>> input = {{1, 5, 9},
    //                              {10, 11, 13},
    //                              {12, 13, 15}};

    vector<vector<int>> input = {{1, 2}, {1, 3}};

    cout << s.kthSmallest(input, 3) << endl;
    return 0;
}
