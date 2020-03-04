#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

// 12ms, 100.00%
// 8.8MB, 100.00%
class Solution {
public:
    vector<int> closestDivisors(int num) {
        int _max = sqrt(num + 2);
        vector<pair<int, int>> res;
        for(int i = 1; i <= _max; ++i) {
            if((num + 1) % i == 0) res.push_back({i, (num + 1)/i});

            if((num + 2 ) % i == 0) res.push_back({i, (num + 2)/i});
        }

        vector<int> min = {0, INT_MAX};
        for(int i = 0; i < res.size(); ++i) {
            int diff = abs(res[i].first - res[i].second);
            if(diff < abs(min[0] - min[1])) {
                min[0] = res[i].first;
                min[1] = res[i].second;
            }
        }

        return min;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> res = s.closestDivisors(1);
    for(auto& e : res){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
