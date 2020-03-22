#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// accept
// 216ms
// 28.1MB
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> v;
        for (int i = 0; i < n; ++i) {
            v.push_back({efficiency[i], speed[i]});
        }

        sort(v.rbegin(), v.rend());

        int mod = 1000000007;
        long long ans = 0;
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> que;

        for (int i = 0; i < n; ++i) {
            int effi = v[i][0];
            sum += v[i][1];

            que.push(v[i][1]);

            if(--k < 0) {
                sum -= que.top();
                que.pop();
            }

            ans = max(ans, sum * effi);
        }
        return ans % mod;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> speed = {2, 10, 3, 1, 5, 8};
    vector<int> efficiency = {5, 4, 3, 9, 7, 2};
    cout << s.maxPerformance(6, speed, efficiency, 2) << endl;
    return 0;
}
