#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 20ms, beats 69.27%
// 13.3MB, beats 8.30%
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) return vector<vector<int>>({newInterval});
        vector<vector<int>> ret;
        int left = -1;
        int right = -1;
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> v = intervals[i];
            if(v[1] < newInterval[0]){
                ret.push_back(v);
            } else {
                if (left == -1) left = i;
            }

            if (newInterval[1] < v[0]) {
                ret.push_back(v);
            } else {
                right = i;
            }
        }

        cout << left << " " << right << endl;
        if (left == -1) {
            // newnode is the last element
            ret.push_back(newInterval);
        } else if (right == -1) {
            // newnode is the first element
            ret.insert(ret.begin(), newInterval);
        } else {
            // merge
            ret.insert(ret.begin() + left,
                       {min(intervals[left][0], newInterval[0]),
                               max(intervals[right][1], newInterval[1])});
        }

        return ret;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<int>> origin = {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};
    vector<int> newnode = {4,8};

    // vector<vector<int>> origin = {{1,3}, {6,9}};
    // vector<int> newnode = {2, 5};

    // vector<vector<int>> origin = {{6,9},{10, 13}};
    // vector<int> newnode = {1,3};

    vector<vector<int>> ret = s.insert(origin, newnode);

    for (auto& e : ret) {
        cout << "[" << e[0] << "," << e[1] << "] ";
    }

    return 0;
}
