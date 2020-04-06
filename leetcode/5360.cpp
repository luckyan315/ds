#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

// accept
// 12ms, beats 100.00%
// 6.2MB, beats 100.00%
class Solution {
public:
    int countLargestGroup(int n) {

        unordered_map<int, int> mp;



        for (int i = 1; i <= n; ++i) {
            int ret = cal(i);
            mp[ret]++;
        }

        int maxcnt = 0;
        int maxnum = 0;
        for (auto& e : mp) {
            if(maxnum < e.second) {
                maxnum = e.second;
                maxcnt = 1;
            } else if(maxnum == e.second){
                maxcnt++;
            }
        }

        return maxcnt;
    }
    int cal(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.countLargestGroup(13) << endl;
    return 0;
}
