#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

// accept
// 0ms, beats 100.00%
// 5.8MB, beats 100.00%
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if(x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2) {
            return true;
        }

        int dx = x_center < x1 ? x1 - x_center : x_center > x2 ? x_center - x2 : 0;
        int dy = y_center < y1 ? y1 - y_center : y_center > y2 ? y_center - y2 : 0;

        return dx * dx + dy * dy <= radius * radius;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.checkOverlap(1, 1, 1, -3, -3, 3, 3) << endl;
    return 0;
}
