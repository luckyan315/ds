#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        // pair.second > 0 时标记为左节点
        // pair.second < 0 时标记为右节点
        multiset<pair<int, int>> splitsBuildings;
        for (auto v : buildings) {
            splitsBuildings.insert({v[0], -v[2]});
            splitsBuildings.insert({v[1], v[2]});
        }

        multiset<int> heights({0});
        vector<int> last = {0, 0};
        for (auto& b : splitsBuildings) {
            if (b.second < 0) heights.insert(-b.second);
            else heights.erase(heights.find(b.second));

            auto maxHeight = *heights.rbegin();

            if (last[1] != maxHeight) {
                last[0] = b.first;
                last[1] = maxHeight;
                res.push_back(last);
            }

        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<int>> bds = {{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
    vector<vector<int>> res = s.getSkyline(bds);
    for (auto& v : res) {
        cout << v[0] << " " << v[1] << endl;
    }

    return 0;
}
