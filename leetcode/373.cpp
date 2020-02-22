#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// accept
// 16ms, beats 92.28%
// 10.3MB, beats 47.94%
class Solution2 {
public:
    struct cmp {
        bool operator () (pair<int, int>& a, pair<int, int>& b){
            return a.first + a.second < b.first + b.second;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ret;
        if (nums1.size() == 0 || nums2.size() == 0) return ret;

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
        vector<vector<int>> res;
        for (size_t i = 0; i < nums1.size(); ++i) {
            for (size_t j = 0; j < nums2.size(); j++) {
                if (que.size() < k) {
                    que.push({nums1[i], nums2[j]});
                } else if (nums1[i] + nums2[j] < que.top().first + que.top().second) {
                    que.pop();
                    que.push({nums1[i], nums2[j]});
                }
            }
        }

        while (!que.empty()) {
            pair<int, int> node = que.top();
            res.push_back({node.first, node.second});
            que.pop();
        }
        return res;
    }
};

// accept
// 164ms, beats 39.87%
// 10.4MB, beats 47.71%
// vector insertion is very slow, need to optimize
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ret;
        if (nums1.size() == 0 || nums2.size() == 0) return ret;

        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); j++) {
                int pos = binarySearchInsertPos(ret, nums1[i] + nums2[j]);
                if (ret.size() < k) {
                    ret.insert(ret.begin() + pos, {nums1[i], nums2[j]});
                } else {
                    if (nums1[i] + nums2[j] < ret.back()[0] + ret.back()[1]) {
                        ret.pop_back();
                        ret.insert(ret.begin() + pos, {nums1[i], nums2[j]});
                    }
                }
            }
        }

        return ret;
    }

    // 1,3,5, cur=0
    int binarySearchInsertPos(vector<vector<int>>& ret, int cur) {
        int l = 0;
        int h = ret.size() - 1;

        // for (auto& e : ret) {
        //     cout << e[0] << " " << e[1] << endl;
        // }

        while (l <= h) {
            int mid = l + (h  - l)/2;
            int midSum = ret[mid][0] + ret[mid][1];
            // cout << "mid: " << mid << " midSum: " << midSum << endl;
            if (cur > midSum) l = mid + 1;
            else if (cur < midSum) h = mid - 1;
            else return mid;
        }
        return l;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    // vector<int> nums1 = {1,1,2};
    // vector<int> nums2 = {1,2,3};

    vector<int> nums1 = {0, 0, 0, 0, 0};
    vector<int> nums2 = {-3, 22, 35, 56, 76};
    int k = 22;
    vector<vector<int>> ret;
    ret = s.kSmallestPairs(nums1, nums2, k);

    for (auto& e : ret) {
        cout << e[0] << " " << e[1] <<endl;
    }

    // 3, 7, 11
    // vector<vector<int>> input = {{1,2}, {3, 4}, {4, 7}};
    // cout << s.binarySearchInsertPos(input, atoi(argv[1])) << endl;
    return 0;
}
