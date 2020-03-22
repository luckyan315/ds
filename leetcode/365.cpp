#include <iostream>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

// accept
// 2008ms, 5.36%
// 289.7MB, 5.43%
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        auto hashfunc = [&] (const pair<int, int>& o) {
            return hash<int>()(o.first) ^ hash<int>()(o.second);
        };
        unordered_set<pair<int, int>, decltype(hashfunc)> vis(0, hashfunc);
        queue<pair<int, int>> que;
        que.push({0, 0});
        while (!que.empty()) {
            if(vis.count(que.front()) != 0) {
                que.pop();
                continue;
            }

            vis.insert(que.front());

            auto [xleft, yleft] = que.front();

            if(xleft == z ||
               yleft == z ||
               xleft + yleft == z) {
                return true;
            }

            que.push({x, yleft});
            que.push({xleft, y});
            que.push({0, yleft});
            que.push({xleft, 0});

            // xleft -> yleft
            int moveNum = std::min(xleft, y - yleft);
            que.push({xleft - moveNum, yleft + moveNum});
            // yleft -> xleft
            moveNum = std::min(x - xleft, yleft);
            que.push({xleft + moveNum, yleft - moveNum});
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.canMeasureWater(2, 5, 4) << endl;

    return 0;
}
