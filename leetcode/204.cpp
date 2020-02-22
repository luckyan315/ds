#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// accept
// 188ms, 29.64%
// 8.9MB, 35.61%
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;

        vector<bool> v(n, true);
        v[0] = false; v[1] = false;

        double s = sqrt(n);
        for(int i = 2; i <= s; ++i){
            if(v[i]) {
                int tmp = 2;
                for(int j = i * tmp; j < n; j = i * ++tmp) {
                    // cout << "set false: " << j << " ";
                    v[j] = false;
                }
                // cout << endl;
            }
        }

        int cnt = 0;
        for(int i = 0; i < v.size(); ++i) {
            if(v[i]) {
                // cout << i << " ";
                cnt++;
            }
        }
        // cout << endl;

        return cnt;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.countPrimes(10) << endl;
    return 0;
}
