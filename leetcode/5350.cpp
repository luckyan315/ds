#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    struct cmp {
        bool operator () (pair<int, int>& a, pair<int, int>& b) {
            if(a.first > b.first) return true;
            if(a.first == b.first) {
                return a.second > b.second;
            }
            return false;
        }
    };

    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;

        for (int i = lo; i <= hi; ++i) {
            que.push({getk(i), i});
        }
        while (--k) {
            que.pop();
        }
        return que.top().second;
    }

    int getk(int num) {
        if(num == 1) return 0;
        if(num % 2 == 0) return 1 + getk(num / 2);
        else return 1 + getk(3 * num + 1);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.getKth(7, 11, 4) << endl;
    return 0;
}
