#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// accept
// 88ms, beats 72.93%
// 13.8MB, 27.77%
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.size() <= 1) return people;
        sort(people.begin(), people.end(), [&](vector<int>& a, vector<int>& b) -> bool {
                if ( a[0] > b[0]) return true;
                if(a[0] == b[0] && a[1] < b[1]) return true;

                return false;
            });

        vector<vector<int>> res;
        res.push_back(people[0]);
        for (int i = 1; i < people.size(); ++i) {
            int cnt = 0;
            int j = 0;
            for (; j < res.size(); ++j) {
                if(res[j][0] >= people[i][0]) cnt++;

                if(cnt > people[i][1]) {
                    res.insert(res.begin() + j, people[i]);
                    break;
                }
            }
            if(j == res.size()) {
                res.push_back(people[i]);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<int>> p = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> res = s.reconstructQueue(p);
    for(auto& e : res) {
        cout << e[0] << " " << e[1] << endl;
    }
    return 0;
}
