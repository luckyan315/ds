#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Success
// Details
// Runtime: 16 ms, faster than 95.70% of C++ online submissions for Container With Most Water.
// Memory Usage: 9.8 MB, less than 79.38% of C++ online submissions for Container With Most Water.
// Next challenges:
class Solution4 {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int area = 0;
        int h = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                h = height[left++];
            } else {
                h = height[right--];
            }

            area = max (area, h * (right - left + 1));
        }

        return area;
    }
};

// Success
// Details
// Runtime: 16 ms, faster than 95.70% of C++ online submissions for Container With Most Water.
// Memory Usage: 9.9 MB, less than 50.52% of C++ online submissions for Container With Most Water.
// Next challenges:
class Solution3 {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int area = 0;
        int h = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                h = height[left];
                left++;
            } else {
                h = height[right];
                right--;
            }

            area = max (area, h * (right - left + 1));
        }

        return area;
    }
};

// Success
// Details
// Runtime: 20 ms, faster than 66.23% of C++ online submissions for Container With Most Water.
// Memory Usage: 9.6 MB, less than 100.00% of C++ online submissions for Container With Most Water.
// Next challenges:

class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int area = 0;
        int h = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                h = height[left];
                left++;
            } else {
                h = height[right];
                right--;
            }

            if (area < h * (right - left + 1)) {
                area = h * (right - left + 1);
            }
        }

        return area;
    }


};

// 垃圾解法， 暴力穷举， 选出最大面积， 时间复杂度稳定 O(n^2)
// Success
// Details
// Runtime: 1284 ms, faster than 6.62% of C++ online submissions for Container With Most Water.
// Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Container With Most Water.
class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int maxh = 0;

        unsigned long max = 0;
        for (int i = 0; i < height.size() - 1; ++i) {
            for (int j = i + 1; j < height.size(); ++j) {
                maxh = height[i] <= height[j] ? height[i] : height[j];
                if (max < (j - i) * maxh) {
                    max = (j - i) * maxh;
                }
            }
        }
        return max;
    }


};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxArea = 0;
        while (i < j) {
            long long area = (j - i) * std::min(height[i], height[j]);
            maxArea = maxArea < area ? area : maxArea;
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxArea;
    }
};


int main(int argc, char *argv[]) {
    Solution *pSln = new Solution();

    vector<int> vec {1,8,6,2,5,4,8,3,7};

    cout<<pSln->maxArea(vec)<<endl;
    delete pSln;
    return 0;
}
