#include <iostream>
#include <vector>

using namespace std;

// accept
// 8ms, beats 88.85%
// 6MB, beats 100.00%
class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            ans = (ans + m) % i;
        }
        return ans;
    }
};

class Solution_timeout {
public:
    int lastRemaining(int n, int m) {
        int i = 0;

        int cnt = n;
        vector<int> vis(n, 0);

        if(m > n) m %= n;
        int freq = m;

        while (cnt) {
            if(vis[i] == 0 && --freq == 0) {
                vis[i] = 1;

                cnt--;
                // cout << "value: " << i << " left count: " << cnt << endl;
                if(cnt == 0) return i;
                freq = m;
            }
            i = (i + 1) % n;
        }
        return i;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.lastRemaining(10, 17) << endl;
    return 0;
}
