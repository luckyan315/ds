#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// accept
// 300ms, beats 100%
// 72.1MB, beats 100%
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> vis;
        for (auto& seat : reservedSeats) {
            vis[seat[0]].insert(seat[1]);
        }

        int res = 0;
        for (auto it : vis) {
            int flag = 0;
            if(it.second.count(2) == 0 &&
               it.second.count(3) == 0) {
                if(it.second.count(4) == 0 &&
               it.second.count(5) == 0) {
                    res++;
                    flag = 1;
                }
            }
            if (it.second.count(8) == 0 &&
               it.second.count(9) == 0) {
                if(it.second.count(6) == 0 &&
               it.second.count(7) == 0) {
                    res++;
                    flag = 1;
                }
            }
            if (it.second.count(4) == 0 &&
               it.second.count(5) == 0) {
                if(it.second.count(6) == 0 &&
               it.second.count(7) == 0 && !flag) res++;
            }
        }
        return res + 2 * (n - vis.size());
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<int>> input = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
    cout << s.maxNumberOfFamilies(3, input) << endl;
    return 0;
}
