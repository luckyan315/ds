#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// accept
// 8ms, beats 76.98%
// 9.3MB, beats 6.65%
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int left = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            left += gas[i] - cost[i];
            if (left < 0) {
                start = i + 1;
                left = 0;
            }
        }

        return total < 0 ? -1 : start;
    }
};

// 8ms, beats 76.98%
// 9.2MB, beats 8.92%
class Solution3 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size(), j = 0;
        for (int i = 0; i < len; i = j + 1) {
            int left = 0;
            for (j = i; j < i + len; ++j) {
                int gasj = j % len;;
                left += gas[gasj] - cost[gasj];
                if (left < 0) break;
            }
            if (left >= 0) return i;
        }
        return -1;
    }
};

// accept
// 156ms, beats 24.00%
// 9.3MB, beats 6.49%
class Solution2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        for (int i = 0; i < len; ++i) {
            int left = 0;
            for (int j = i; j < i + len; ++j) {
                int gasj = j % len;;
                left += gas[gasj] - cost[gasj];
                if (left < 0) break;
            }
            if (left >= 0) return i;
        }
        return -1;
    }
};

class Solution1 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int left = 0;
        int i = 0;
        int cnt = 1;
        for (; i < gas.size() && cnt <= gas.size(); cnt++, i++) {
            if (i >= gas.size()) i = cnt % gas.size();
            left += gas[i] - cost[i];
            cout << "i:" << i << " gas[i]:" << gas[i] << " cost[i]: " << cost[i]
                 << " left: " << left << " cnt: " << cnt <<endl;
            if (left < 0) {
                cnt = 0;
                continue;
            }
            return i - cnt;
        }

        return -1;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    // vector<int> gas = {5,1,2,3,4};
    // vector<int> cost = {4,4,1,5,1};
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
