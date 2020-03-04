#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// accept
// 20ms, 71.31%
// 11.7MB, 57.58%
class Solution {
public:
    long gcd(const long a, const long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <= 1) return points.size();

        int max = 0;
        for(int i = 0; i < points.size(); ++i) {
            map<double, int> _map;
            int ax = points[i][0];
            int ay = points[i][1];
            int sameCnt = 0;
            int lineMax = 0;
            for (int j = i + 1; j < points.size(); j++) {
                int bx = points[j][0];
                int by = points[j][1];

                long diffx = bx - ax;
                long diffy = by - ay;
                if(diffx == 0 && diffy == 0) {
                    sameCnt++;
                    continue;
                }

                int g = gcd(diffx, diffy);
                diffx /= g;
                diffy /= g;

                if(diffx < 0) {
                    // leet code not support nagative number shift lefting
                    // so change it to positive number
                    diffx = -1 * diffx;
                    diffy = -1 * diffy;
                }

                double key = (diffx << 32) + diffy;
                if(_map.count(key) != 0) ++_map[key];
                else _map.insert({key, 1});
                lineMax = std::max(lineMax, _map[key]);
            }

            max = std::max(lineMax + sameCnt + 1, max);
        }

        return max;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    // vector<vector<int>> points = {{1, 1}, {2,2}, {3,3}};
    // vector<vector<int>> points = {{1, 1}, {3,2}, {5,3}, {4,1}, {2,3}, {1, 4}};
    vector<vector<int>> points = {{0, 0},{0, 0}};
    cout << s.maxPoints(points) << endl;
    return 0;
}
